#pragma once

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::Label^  labelEiler;
	public:
	private: System::Windows::Forms::TextBox^  textBoxEiler;
	private: System::Windows::Forms::Button^  buttonClear;
			 String^ fileName;
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBoxRsa;
	private: System::Windows::Forms::Button^  buttonOpen;
	private: System::Windows::Forms::Label^  labelKs;
	protected:

	protected:




	private: System::Windows::Forms::Label^  labelQ;
	private: System::Windows::Forms::Label^  labelP;
	private: System::Windows::Forms::TextBox^  textBoxQ;
	private: System::Windows::Forms::TextBox^  textBoxKs;






	private: System::Windows::Forms::TextBox^  textBoxP;
	private: System::Windows::Forms::Label^  labelKo;


	private: System::Windows::Forms::Label^  labelR;
	private: System::Windows::Forms::TextBox^  textBoxR;
	private: System::Windows::Forms::TextBox^  textBoxKo;
	private: System::Windows::Forms::Button^  buttonExecute;
	private: System::Windows::Forms::TextBox^  textBoxFileName;
	private: System::Windows::Forms::TextBox^  textBoxPlain;
	private: System::Windows::Forms::Label^  labelPlain;
	private: System::Windows::Forms::Label^  labelCipher;
	private: System::Windows::Forms::TextBox^  textBoxCipher;
	private: System::Windows::Forms::ComboBox^  comboBoxTask;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBoxRsa = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->labelEiler = (gcnew System::Windows::Forms::Label());
			this->textBoxEiler = (gcnew System::Windows::Forms::TextBox());
			this->buttonExecute = (gcnew System::Windows::Forms::Button());
			this->textBoxKo = (gcnew System::Windows::Forms::TextBox());
			this->labelKo = (gcnew System::Windows::Forms::Label());
			this->labelKs = (gcnew System::Windows::Forms::Label());
			this->labelQ = (gcnew System::Windows::Forms::Label());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->labelP = (gcnew System::Windows::Forms::Label());
			this->textBoxR = (gcnew System::Windows::Forms::TextBox());
			this->textBoxQ = (gcnew System::Windows::Forms::TextBox());
			this->textBoxKs = (gcnew System::Windows::Forms::TextBox());
			this->textBoxP = (gcnew System::Windows::Forms::TextBox());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->textBoxFileName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPlain = (gcnew System::Windows::Forms::TextBox());
			this->labelPlain = (gcnew System::Windows::Forms::Label());
			this->labelCipher = (gcnew System::Windows::Forms::Label());
			this->textBoxCipher = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxTask = (gcnew System::Windows::Forms::ComboBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBoxRsa->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxRsa
			// 
			this->groupBoxRsa->Controls->Add(this->buttonClear);
			this->groupBoxRsa->Controls->Add(this->labelEiler);
			this->groupBoxRsa->Controls->Add(this->textBoxEiler);
			this->groupBoxRsa->Controls->Add(this->buttonExecute);
			this->groupBoxRsa->Controls->Add(this->textBoxKo);
			this->groupBoxRsa->Controls->Add(this->labelKo);
			this->groupBoxRsa->Controls->Add(this->labelKs);
			this->groupBoxRsa->Controls->Add(this->labelQ);
			this->groupBoxRsa->Controls->Add(this->labelR);
			this->groupBoxRsa->Controls->Add(this->labelP);
			this->groupBoxRsa->Controls->Add(this->textBoxR);
			this->groupBoxRsa->Controls->Add(this->textBoxQ);
			this->groupBoxRsa->Controls->Add(this->textBoxKs);
			this->groupBoxRsa->Controls->Add(this->textBoxP);
			this->groupBoxRsa->Location = System::Drawing::Point(12, 55);
			this->groupBoxRsa->Name = L"groupBoxRsa";
			this->groupBoxRsa->Size = System::Drawing::Size(274, 220);
			this->groupBoxRsa->TabIndex = 0;
			this->groupBoxRsa->TabStop = false;
			this->groupBoxRsa->Text = L"RSA";
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(18, 188);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(100, 23);
			this->buttonClear->TabIndex = 9;
			this->buttonClear->Text = L"Очистить поля";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// labelEiler
			// 
			this->labelEiler->AutoSize = true;
			this->labelEiler->Location = System::Drawing::Point(149, 135);
			this->labelEiler->Name = L"labelEiler";
			this->labelEiler->Size = System::Drawing::Size(99, 13);
			this->labelEiler->TabIndex = 8;
			this->labelEiler->Text = L"Функция Эйлера r";
			// 
			// textBoxEiler
			// 
			this->textBoxEiler->Location = System::Drawing::Point(152, 151);
			this->textBoxEiler->Name = L"textBoxEiler";
			this->textBoxEiler->ReadOnly = true;
			this->textBoxEiler->Size = System::Drawing::Size(100, 20);
			this->textBoxEiler->TabIndex = 7;
			// 
			// buttonExecute
			// 
			this->buttonExecute->Location = System::Drawing::Point(152, 188);
			this->buttonExecute->Name = L"buttonExecute";
			this->buttonExecute->Size = System::Drawing::Size(100, 23);
			this->buttonExecute->TabIndex = 6;
			this->buttonExecute->Text = L"Выполнить";
			this->buttonExecute->UseVisualStyleBackColor = true;
			this->buttonExecute->Click += gcnew System::EventHandler(this, &MainForm::buttonExecute_Click);
			// 
			// textBoxKo
			// 
			this->textBoxKo->Location = System::Drawing::Point(152, 98);
			this->textBoxKo->MaxLength = 5;
			this->textBoxKo->Name = L"textBoxKo";
			this->textBoxKo->Size = System::Drawing::Size(100, 20);
			this->textBoxKo->TabIndex = 3;
			this->textBoxKo->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxKo_KeyPress);
			// 
			// labelKo
			// 
			this->labelKo->AutoSize = true;
			this->labelKo->Location = System::Drawing::Point(149, 82);
			this->labelKo->Name = L"labelKo";
			this->labelKo->Size = System::Drawing::Size(90, 13);
			this->labelKo->TabIndex = 2;
			this->labelKo->Text = L"Открытый ключ ";
			// 
			// labelKs
			// 
			this->labelKs->AutoSize = true;
			this->labelKs->Location = System::Drawing::Point(149, 29);
			this->labelKs->Name = L"labelKs";
			this->labelKs->Size = System::Drawing::Size(90, 13);
			this->labelKs->TabIndex = 5;
			this->labelKs->Text = L"Закрытый ключ ";
			// 
			// labelQ
			// 
			this->labelQ->AutoSize = true;
			this->labelQ->Location = System::Drawing::Point(15, 82);
			this->labelQ->Name = L"labelQ";
			this->labelQ->Size = System::Drawing::Size(67, 13);
			this->labelQ->TabIndex = 4;
			this->labelQ->Text = L"Параметр q";
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(15, 135);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(51, 13);
			this->labelR->TabIndex = 1;
			this->labelR->Text = L"Модуль r";
			// 
			// labelP
			// 
			this->labelP->AutoSize = true;
			this->labelP->Location = System::Drawing::Point(15, 29);
			this->labelP->Name = L"labelP";
			this->labelP->Size = System::Drawing::Size(67, 13);
			this->labelP->TabIndex = 3;
			this->labelP->Text = L"Параметр p";
			// 
			// textBoxR
			// 
			this->textBoxR->Location = System::Drawing::Point(18, 151);
			this->textBoxR->MaxLength = 5;
			this->textBoxR->Name = L"textBoxR";
			this->textBoxR->Size = System::Drawing::Size(100, 20);
			this->textBoxR->TabIndex = 0;
			this->textBoxR->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxR_TextChanged);
			this->textBoxR->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxR_KeyPress);
			// 
			// textBoxQ
			// 
			this->textBoxQ->Location = System::Drawing::Point(18, 98);
			this->textBoxQ->MaxLength = 5;
			this->textBoxQ->Name = L"textBoxQ";
			this->textBoxQ->Size = System::Drawing::Size(100, 20);
			this->textBoxQ->TabIndex = 2;
			this->textBoxQ->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxQ_TextChanged);
			this->textBoxQ->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxQ_KeyPress);
			// 
			// textBoxKs
			// 
			this->textBoxKs->Location = System::Drawing::Point(152, 45);
			this->textBoxKs->MaxLength = 5;
			this->textBoxKs->Name = L"textBoxKs";
			this->textBoxKs->Size = System::Drawing::Size(100, 20);
			this->textBoxKs->TabIndex = 1;
			this->textBoxKs->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxKs_KeyPress);
			// 
			// textBoxP
			// 
			this->textBoxP->Location = System::Drawing::Point(18, 45);
			this->textBoxP->MaxLength = 5;
			this->textBoxP->Name = L"textBoxP";
			this->textBoxP->Size = System::Drawing::Size(100, 20);
			this->textBoxP->TabIndex = 0;
			this->textBoxP->TextChanged += gcnew System::EventHandler(this, &MainForm::textBoxP_TextChanged);
			this->textBoxP->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::textBoxP_KeyPress);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(12, 17);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(100, 23);
			this->buttonOpen->TabIndex = 6;
			this->buttonOpen->Text = L"Выбрать файл";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MainForm::buttonOpen_Click);
			// 
			// textBoxFileName
			// 
			this->textBoxFileName->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxFileName->Location = System::Drawing::Point(118, 19);
			this->textBoxFileName->Name = L"textBoxFileName";
			this->textBoxFileName->ReadOnly = true;
			this->textBoxFileName->Size = System::Drawing::Size(304, 20);
			this->textBoxFileName->TabIndex = 7;
			// 
			// textBoxPlain
			// 
			this->textBoxPlain->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxPlain->Location = System::Drawing::Point(292, 71);
			this->textBoxPlain->Multiline = true;
			this->textBoxPlain->Name = L"textBoxPlain";
			this->textBoxPlain->ReadOnly = true;
			this->textBoxPlain->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxPlain->Size = System::Drawing::Size(257, 86);
			this->textBoxPlain->TabIndex = 8;
			// 
			// labelPlain
			// 
			this->labelPlain->AutoSize = true;
			this->labelPlain->Location = System::Drawing::Point(292, 55);
			this->labelPlain->Name = L"labelPlain";
			this->labelPlain->Size = System::Drawing::Size(89, 13);
			this->labelPlain->TabIndex = 9;
			this->labelPlain->Text = L"Исходный текст";
			// 
			// labelCipher
			// 
			this->labelCipher->AutoSize = true;
			this->labelCipher->Location = System::Drawing::Point(292, 170);
			this->labelCipher->Name = L"labelCipher";
			this->labelCipher->Size = System::Drawing::Size(70, 13);
			this->labelCipher->TabIndex = 10;
			this->labelCipher->Text = L"Шифротекст";
			// 
			// textBoxCipher
			// 
			this->textBoxCipher->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxCipher->Location = System::Drawing::Point(292, 186);
			this->textBoxCipher->Multiline = true;
			this->textBoxCipher->Name = L"textBoxCipher";
			this->textBoxCipher->ReadOnly = true;
			this->textBoxCipher->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxCipher->Size = System::Drawing::Size(257, 89);
			this->textBoxCipher->TabIndex = 11;
			// 
			// comboBoxTask
			// 
			this->comboBoxTask->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTask->FormattingEnabled = true;
			this->comboBoxTask->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Шифрование", L"Дешифрование", L"Взлом" });
			this->comboBoxTask->Location = System::Drawing::Point(428, 19);
			this->comboBoxTask->Name = L"comboBoxTask";
			this->comboBoxTask->Size = System::Drawing::Size(121, 21);
			this->comboBoxTask->TabIndex = 12;
			this->comboBoxTask->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxTask_SelectedIndexChanged);
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(561, 287);
			this->Controls->Add(this->comboBoxTask);
			this->Controls->Add(this->textBoxCipher);
			this->Controls->Add(this->labelCipher);
			this->Controls->Add(this->labelPlain);
			this->Controls->Add(this->textBoxPlain);
			this->Controls->Add(this->textBoxFileName);
			this->Controls->Add(this->buttonOpen);
			this->Controls->Add(this->groupBoxRsa);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Лабораторная 4 - Алгоритм RSA";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBoxRsa->ResumeLayout(false);
			this->groupBoxRsa->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonExecute_Click(System::Object^  sender, System::EventArgs^  e);
    
    private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);

	private: System::Void comboBoxTask_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);

	void encryptRSA(unsigned short p, unsigned short q, unsigned short secretKey);

	void decryptRSA(unsigned short r, unsigned short secretKey);

	void breakRSA(unsigned short r, unsigned short publicKey);

	private: System::Void textBoxP_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxQ_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxR_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxKs_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	private: System::Void textBoxKo_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e);

	void checkPQ();

	private: System::Void textBoxP_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxQ_TextChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void textBoxR_TextChanged(System::Object^  sender, System::EventArgs^  e);
};
}
