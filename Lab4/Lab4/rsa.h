#ifndef RSA_H
#define RSA_H

bool isPrime(unsigned short);

unsigned short getGreatestCommonDivider(unsigned short, unsigned short);

unsigned short getCipher(unsigned short, unsigned short, unsigned short, unsigned short);

unsigned short getPlain(unsigned short value, unsigned short r, unsigned short key);

unsigned short getEuclidExtended(unsigned short, int);

unsigned short getMultiplyInverse(unsigned short, unsigned short);

int fastExp(unsigned long long, unsigned short, unsigned short);

unsigned short getDivider(unsigned short value);

#endif