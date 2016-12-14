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

unsigned short getCipher(unsigned short value, unsigned short p, unsigned short q, unsigned short key)
{
	int r = p * q;
	int eilerR = (p - 1) * (q - 1);
	int e = getMultiplyInverse(key, eilerR);
	return fastExp(value, e, r);
}

unsigned short getDivider(unsigned short value)
{
	unsigned short result = 2;
	while (!(value % result == 0 && isPrime(value / result) && isPrime(result)) && result != value)
	{
		result++;
	}
	return result;
}

unsigned short getPlain(unsigned short value, unsigned short r, unsigned short key)
{
	int p = getDivider(r);
	int q = r / p;
	int eilerR = (p - 1) * (q - 1);
	return fastExp(value, key, r);
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

unsigned short getMultiplyInverse(unsigned short value, unsigned short mod)
{
	return getEuclidExtended(value, mod);
}

int fastExp(unsigned long long value, unsigned short power, unsigned short modula)
{ 
	unsigned long long result = 1;
	while (power != 0)
	{
		while (power % 2 == 0)
		{
			power = power / 2;
			value = (value * value) % modula;
		}
		power -= 1;
		result = (result * value) % modula;
	}
	return result;
}