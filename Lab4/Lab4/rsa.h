#ifndef RSA_H
#define RSA_H

bool isPrime(unsigned short);

unsigned short getGreatestCommonDivider(unsigned short, unsigned short);

unsigned short getDivider(unsigned short value);

unsigned short getKey(unsigned short p, unsigned short q, unsigned short key);

unsigned short getCipher(unsigned short, unsigned short, unsigned short, unsigned short);

unsigned short getPlain(unsigned short, unsigned short, unsigned short);

unsigned short breakCipher(unsigned short, unsigned short, unsigned short, unsigned short);

unsigned short getEuclidExtended(unsigned short b, int a);
#endif