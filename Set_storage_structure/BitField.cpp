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
TBitField::~TBitField()
{
	delete pMem;
}
