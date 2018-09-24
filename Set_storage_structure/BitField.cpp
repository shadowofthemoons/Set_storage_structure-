#include "pch.h"
#include "BitField.h"
#include <iostream>
using namespace std;



TBitField::TBitField(int len)
{
	BitLen = len;
	MemLen = ((len + 31) >> 5);
	pMem = new uint[MemLen];
	if (pMem == NULL)
	{
		cout << "error in creating an array";
		exit(1);
	}
	for (int i=0;i<MemLen;i++)
	{
		pMem[i] = 0;
	}
}
TBitField::TBitField(const TBitField &bf)
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new uint[MemLen];
	if (pMem == NULL)
	{
		cout << "error in creating an array";
		exit(1);
	}
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
}

int TBitField:: GetMemIndex(const int n) const
{
	return (n/32);
}

uint TBitField::GetMemMask(const int n) const
{
	uint a = 1;
	return ((a << (n%32)));
}

int TBitField::GetLength(void) const
{
	return (BitLen);
}

void TBitField::SetBit(const int n)
{
	int MemIndex = GetMemIndex(n);
	int MemMask = GetMemMask(n);
	pMem[MemIndex] = pMem[MemIndex] | MemMask;
}
void TBitField::ClrBit(const int n)
{
	int MemIndex = GetMemIndex(n);
	int MemMask = GetMemMask(n);
	pMem[MemIndex] = pMem[MemIndex] & (~MemMask);
}

TBitField::~TBitField()
{
	delete pMem;
}
