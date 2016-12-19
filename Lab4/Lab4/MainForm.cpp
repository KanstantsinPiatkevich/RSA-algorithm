#include "MainForm.h"
#include <math.h>
#include "rsa.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;

namespace Lab4
{
	System::Void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		comboBoxTask->SelectedIndex = 0;
	}

	System::Void MainForm::comboBoxTask_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		switch (comboBoxTask->SelectedIndex)
		{
		case 0:
			textBoxP->Enabled = true;
			textBoxQ->Enabled = true;
			textBoxKs->Enabled = true;
			textBoxKo->Enabled = false;
			textBoxR->Enabled = false;
			break;
		case 1:
			textBoxP->Enabled = false;
			textBoxQ->Enabled = false;
			textBoxKs->Enabled = true;
			textBoxKo->Enabled = false;
			textBoxR->Enabled = true;
			break;
		case 2:
			textBoxP->Enabled = false;
			textBoxQ->Enabled = false;
			textBoxKs->Enabled = false;
			textBoxKo->Enabled = true;
			textBoxR->Enabled = true;
			break;
		}
	}

	System::Void MainForm::buttonOpen_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (openFileDialog->FileName != "")
			{
				fileName = openFileDialog->FileName;
				textBoxFileName->Text = fileName;
			}
		}
	}

	void MainForm::encryptRSA(unsigned short p, unsigned short q, unsigned short secretKey)
	{
		System::IO::BinaryReader^ plainReader = gcnew System::IO::BinaryReader(gcnew System::IO::FileStream(fileName, System::IO::FileMode::Open), System::Text::Encoding::ASCII);
		if (plainReader->BaseStream->Position == plainReader->BaseStream->Length)
			MessageBox::Show("Файл пуст!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
		{
			textBoxR->Text = (p * q).ToString();
			textBoxKo->Text = getKey(p, q, secretKey).ToString();
			textBoxPlain->Text = "";
			textBoxCipher->Text = "";
			System::IO::BinaryWriter^ cipherWriter = gcnew System::IO::BinaryWriter(gcnew System::IO::FileStream(fileName->Insert(fileName->IndexOf('.'), "_cip"), System::IO::FileMode::Create), System::Text::Encoding::ASCII);
			int pos = 0;
			while (plainReader->BaseStream->Position != plainReader->BaseStream->Length)
			{
				unsigned char plain = plainReader->ReadByte();
				unsigned short cipher = getCipher(plain, p, q, secretKey);
				if (plainReader->BaseStream->Position < 64 || (plainReader->BaseStream->Length - plainReader->BaseStream->Position <= 64 && plainReader->BaseStream->Position >= 64))
				{
					pos++;
					textBoxCipher->Text += cipher.ToString() + " ";
					textBoxPlain->Text += plain.ToString() + " ";
					if (pos % 8 == 0 && pos != 0)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
					if (plainReader->BaseStream->Length - plainReader->BaseStream->Position == 64)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
				}
				cipherWriter->Write(cipher);
			}
			cipherWriter->Close();
			MessageBox::Show("Результат шифрования записан в файл " + fileName->Insert(fileName->IndexOf('.'), "_cip"), "Шифрование завершено", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		plainReader->Close();
	}

	void MainForm::decryptRSA(unsigned short r, unsigned short secretKey)
	{
		System::IO::BinaryReader^ cipherReader = gcnew System::IO::BinaryReader(gcnew System::IO::FileStream(fileName, System::IO::FileMode::Open), System::Text::Encoding::ASCII);
		if (cipherReader->BaseStream->Position == cipherReader->BaseStream->Length)
			MessageBox::Show("Файл пуст!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else if (cipherReader->BaseStream->Length % 2 != 0)
			MessageBox::Show("Файл должен содержать чётное число байтов!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
		{
			textBoxP->Text = getDivider(r).ToString();
			textBoxQ->Text = (r / getDivider(r)).ToString();
			textBoxKo->Text = getKey(getDivider(r), r / getDivider(r), secretKey).ToString();
			textBoxPlain->Text = "";
			textBoxCipher->Text = "";
			System::IO::BinaryWriter^ plainWriter = gcnew System::IO::BinaryWriter(gcnew System::IO::FileStream(fileName->Insert(fileName->IndexOf('.'), "_pln"), System::IO::FileMode::Create), System::Text::Encoding::ASCII);
			int pos = 0;
			while (cipherReader->BaseStream->Position != cipherReader->BaseStream->Length)
			{
				unsigned short cipher = cipherReader->ReadInt16();
				unsigned char plain = getPlain(cipher, r, secretKey);
				if (cipherReader->BaseStream->Position < 128 || (cipherReader->BaseStream->Length - cipherReader->BaseStream->Position <= 128 && cipherReader->BaseStream->Position >= 128))
				{
					pos++;
					textBoxCipher->Text += cipher.ToString() + " ";
					textBoxPlain->Text += plain.ToString() + " ";
					if (pos % 8 == 0 && pos != 0)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
					if (cipherReader->BaseStream->Length - cipherReader->BaseStream->Position == 128)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
				}
				plainWriter->Write(plain);
			}
			plainWriter->Close();
			MessageBox::Show("Результат дешифрования записан в файл " + fileName->Insert(fileName->IndexOf('.'), "_pln"), "Шифрование завершено", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		cipherReader->Close();
	}

	void MainForm::breakRSA(unsigned short r, unsigned short publicKey)
	{
		System::IO::BinaryReader^ cipherReader = gcnew System::IO::BinaryReader(gcnew System::IO::FileStream(fileName, System::IO::FileMode::Open), System::Text::Encoding::ASCII);
		if (cipherReader->BaseStream->Position == cipherReader->BaseStream->Length)
			MessageBox::Show("Файл пуст!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else if (cipherReader->BaseStream->Length % 2 != 0)
			MessageBox::Show("Файл должен содержать чётное число байтов!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
		{
			textBoxP->Text = getDivider(r).ToString();
			textBoxQ->Text = (r / getDivider(r)).ToString();
			textBoxKs->Text = getKey(getDivider(r), r / getDivider(r), publicKey).ToString();
			textBoxPlain->Text = "";
			textBoxCipher->Text = "";
			System::IO::BinaryWriter^ plainWriter = gcnew System::IO::BinaryWriter(gcnew System::IO::FileStream(fileName->Insert(fileName->IndexOf('.'), "_pln_br"), System::IO::FileMode::Create), System::Text::Encoding::ASCII);
			int pos = 0;
			while (cipherReader->BaseStream->Position != cipherReader->BaseStream->Length)
			{
				unsigned short cipher = cipherReader->ReadInt16();
				unsigned char plain = breakCipher(cipher, getDivider(r), r / getDivider(r), publicKey);
				if (cipherReader->BaseStream->Position < 128 || (cipherReader->BaseStream->Length - cipherReader->BaseStream->Position <= 128 && cipherReader->BaseStream->Position >= 128))
				{
					pos++;
					textBoxCipher->Text += cipher.ToString() + " ";
					textBoxPlain->Text += plain.ToString() + " ";
					if (pos % 8 == 0 && pos != 0)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
					if (cipherReader->BaseStream->Length - cipherReader->BaseStream->Position == 128)
					{
						textBoxPlain->Text += Environment::NewLine;
						textBoxCipher->Text += Environment::NewLine;
					}
				}
				plainWriter->Write(plain);
			}
			plainWriter->Close();
			MessageBox::Show("Результат дешифрования записан в файл " + fileName->Insert(fileName->IndexOf('.'), "_pln_br"), "Шифрование завершено", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		cipherReader->Close();
	}

	bool checkEncryptData(unsigned short p, unsigned short q, unsigned short key)
	{
		if (!isPrime(p))
		{
			MessageBox::Show("Значение p должно быть простым числом!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (!isPrime(q))
		{
			MessageBox::Show("Значение q должно быть простым числом!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (p == q)
		{
			MessageBox::Show("Значения p и q должны быть разными!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (p * q < 256)
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть больше 255!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (p * q > 65535)
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть не больше 65535!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (key >= (p - 1) * (q - 1) || key < 2)
		{
			MessageBox::Show("Значение закрытого ключа должно быть меньше функции Эйлера от произведения p и q (модуля r) и больше 1!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (getGreatestCommonDivider(key, (p - 1) * (q - 1)) != 1)
		{
			MessageBox::Show("Значение секретного ключа и функции Эйлера от произведения p и q (модуля r) должны быть взаимно простыми!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}

		return true;
	}

	bool checkDecryptData(unsigned short r, unsigned short key)
	{
		if (r == 0)
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть произведением простых чисел!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (isPrime(r) || !isPrime(getDivider(r)))
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть произведением простых чисел!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (r < 256)
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть больше 255!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (r > 65535)
		{
			MessageBox::Show("Значение произведения p и q (модуля r) должно быть не больше 65535!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (key >= (getDivider(r) - 1) * (r / getDivider(r) - 1) || key < 2)
		{
			MessageBox::Show("Значение ключа должно быть меньше функции Эйлера от произведения p и q (модуля r) и больше 1!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		if (getGreatestCommonDivider(key, (getDivider(r) - 1) * (r / getDivider(r) - 1)) != 1)
		{
			MessageBox::Show("Значение ключа и функции Эйлера от произведения p и q (модуля r) должны быть взаимно простыми!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}

		return true;
	}

	System::Void MainForm::buttonExecute_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (fileName == nullptr)
			MessageBox::Show("Файл не выбран!", "Ошибка чтения", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else switch (comboBoxTask->SelectedIndex)
		{
		case 0:
			if (textBoxP->Text == "" ||
				textBoxQ->Text == "" ||
				textBoxKs->Text == "")
				MessageBox::Show("Не все поля для ввода заполнены!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else if (checkEncryptData(Int32::Parse(textBoxP->Text), Int32::Parse(textBoxQ->Text), Int32::Parse(textBoxKs->Text)))
				encryptRSA(Int32::Parse(textBoxP->Text), Int32::Parse(textBoxQ->Text), Int32::Parse(textBoxKs->Text));
			break;
		case 1:
			if (textBoxR->Text == "" ||
				textBoxKs->Text == "")
				MessageBox::Show("Не все поля для ввода заполнены!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else if (checkDecryptData(Int32::Parse(textBoxR->Text), Int32::Parse(textBoxKs->Text)))
				decryptRSA(Int32::Parse(textBoxR->Text), Int32::Parse(textBoxKs->Text));
			break;
		case 2:
			if (textBoxR->Text == "" ||
				textBoxKo->Text == "")
				MessageBox::Show("Не все поля для ввода заполнены!", "Ошибка данных", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else if (checkDecryptData(Int32::Parse(textBoxR->Text), Int32::Parse(textBoxKo->Text)))
				breakRSA(Int32::Parse(textBoxR->Text), Int32::Parse(textBoxKo->Text));
			break;
		}
	}

	System::Void MainForm::textBoxP_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxQ_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxR_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxKs_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
			e->KeyChar = 0;
	}

	System::Void MainForm::textBoxKo_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
	{
		if ((e->KeyChar < '0' || e->KeyChar > '9') && e->KeyChar != 8)
			e->KeyChar = 0;
	}

	void MainForm::checkPQ()
	{
		if (textBoxP->Text != "" && textBoxQ->Text != "")
		{
			if (isPrime(Int64::Parse(textBoxP->Text)) && isPrime(Int64::Parse(textBoxQ->Text)))
				textBoxEiler->Text = ((Int64::Parse(textBoxP->Text) - 1) * (Int64::Parse(textBoxQ->Text) - 1)).ToString();
			else
				textBoxEiler->Text = "";
		}
		else
			textBoxEiler->Text = "";
	}

	System::Void MainForm::textBoxP_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		checkPQ();
	}

	System::Void MainForm::textBoxQ_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		checkPQ();
	}

	System::Void MainForm::buttonClear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBoxP->Text = "";
		textBoxQ->Text = "";
		textBoxR->Text = "";
		textBoxKo->Text = "";
		textBoxKs->Text = "";
	}

	System::Void MainForm::textBoxR_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (textBoxR->Text != "" && !isPrime(Int64::Parse(textBoxR->Text)) && isPrime(getDivider(Int64::Parse(textBoxR->Text))))
			textBoxEiler->Text = ((getDivider(Int64::Parse(textBoxR->Text)) - 1) * (Int64::Parse(textBoxR->Text) / getDivider(Int64::Parse(textBoxR->Text)) - 1)).ToString();
		else
			textBoxEiler->Text = "";
	}
}
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab4::MainForm form;
	Application::Run(%form);
}