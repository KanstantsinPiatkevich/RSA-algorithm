#include "rsa.h"
#include <math.h>

bool isPrime(unsigned short value)
{
	if (value == 1)
		return false;

	if (value == 2)
		return true;

	if (value % 2 == 0)
		return false;

	bool result = true;
	for (int i = 3; i <= sqrt((float)value); i++)
	{
		if (value % i == 0)
			result = false;
	}

	return result;
}

unsigned short getGreatestCommonDivider(unsigned short firstNumber, unsigned short secondNumber)
{
	while (secondNumber != 0)
	{
		int temp = firstNumber % secondNumber;
		firstNumber = secondNumber;
		secondNumber = temp;
	}
	return firstNumber;
}

unsigned short getMultiplyInverse(unsigned short value, unsigned short mod)
{
    int a = mod;
	int b = value;
	int x0 = 1, x1 = 0;
	int y0 = 0, y1 = 1;

	while (b > 1)
	{
		int q = a / b;
		int temp = a % b;
		int x2 = x0 - q * x1;
		int y2 = y0 - q * y1;
		a = b;
		b = temp;
		x0 = x1;
		x1 = x2;
		y0 = y1;
		y1 = y2;
	}

	if (y1 < 0)
		y1 += mod;

	return y1;
}

unsigned short getKey(unsigned short p, unsigned short q, unsigned short key)
{
	unsigned short eilerR = (p - 1) * (q - 1);
	return getMultiplyInverse(key, eilerR);
}

int getFastExp(unsigned long long value, unsigned short power, unsigned short mod)
{
	value = 9;
	power = 6;
	mod = 30;
	unsigned long long result = 1;
	while (power != 0)
	{
		while (power % 2 == 0)
		{
			power = power / 2;
			value = (value * value) % mod;
		}
		power -= 1;
		result = (result * value) % mod;
	}

	return result;
}

unsigned short getDivider(unsigned short value)
{
	if (value == 1)
		return 1;

	unsigned short result = 2;
	while (!(value % result == 0 && isPrime(value / result) && isPrime(result)) && result <= value / 2)
	{
		result++;
	}

	if (result > value / 2)
		result = value;

	return result;
}

unsigned short getCipher(unsigned short value, unsigned short p, unsigned short q, unsigned short secretKey)
{
	unsigned short r = p * q;
	unsigned short publicKey = getKey(p, q, secretKey);
	return getFastExp(value, publicKey, r);
}

unsigned short getPlain(unsigned short value, unsigned short r, unsigned short key)
{
	return getFastExp(value, key, r);
}

unsigned short breakCipher(unsigned short value, unsigned short p, unsigned short q, unsigned short publicKey)
{
	unsigned short r = p * q;
	unsigned short secretKey = getKey(p, q, publicKey);
	return getFastExp(value, secretKey, r);
}

unsigned short getEuclidExtended(unsigned short b, int a)
{
	int d0 = a;
	int d1 = b;
	int x0 = 1, x1 = 0;
	int y0 = 0, y1 = 1;
	while (d1 > 1)
	{
		int q = d0 / d1;
	    int d2 = d0 % d1;
	    int x2 = x0 - q * x1;
	    int y2 = y0 - q * y1;
	    d0 = d1; 
	    d1 = d2;
		x0 = x1; 
	    x1 = x2;
	    y0 = y1; 
	    y1 = y2;
	}
	if (y1 < 0)
		y1 += a;
	return y1;
}
