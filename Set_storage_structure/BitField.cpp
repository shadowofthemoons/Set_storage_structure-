#include "pch.h"
#include "BitField.h"
#include <iostream>
using namespace std;


TBitField::TBitField()
{
	BitLen = 0;
	MemLen = 0;
	pMem = NULL;
	
}

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
int TBitField::GetBit(const int n) const
{
	int MemIndex = GetMemIndex(n);
	int MemMask = GetMemMask(n);
	if ((pMem[MemIndex] & MemMask )!= 0)
	{
		return 1;
	}
	return 0;
}

int TBitField:: operator == (const TBitField &bf)
{

	if (BitLen == bf.BitLen )
	{
		int i;
		for ( i = 0; i < MemLen; i++)
		{
			if (pMem[i] != bf.pMem[i])
			{
				break;
			}
		}
		if (i == MemLen)
		{
			return 1;
		}
	}
	return 0;
}

TBitField& TBitField::operator=(const TBitField &bf)
{
	delete pMem;
	pMem = new uint[bf.MemLen];
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	if (pMem == NULL)
	{
		cout << "error in creating an array";
		exit(1);
	}
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = bf.pMem[i];
	}
	return *this;
}

TBitField TBitField:: operator|(const TBitField &bf)
{
	int i, len = BitLen;
	if (bf.BitLen > len)
		len = bf.BitLen;
	TBitField temp(len);
	for (i = 0; i < MemLen; i++)
		temp.pMem[i] = pMem[i];
	for (i = 0; i < bf.MemLen; i++)
		temp.pMem[i] |= bf.pMem[i];
	return temp;
}

TBitField TBitField::operator&(const TBitField &bf)
{
	int i, len = BitLen;
	if (bf.BitLen < len)
		len = bf.BitLen;
	TBitField temp(len);
	for (i = 0; i < MemLen; i++)
		temp.pMem[i] = pMem[i];
	for (i = 0; i < bf.MemLen; i++)
		temp.pMem[i] &= bf.pMem[i];
	return temp;
}

TBitField TBitField::operator~(void)
{
	for (int i = 0; i < MemLen; i++)
	{
		pMem[i] = ~pMem[i];
	}
	return *this;
}

istream & operator >>(istream &ist, TBitField &bf)
{
	int b,n;
	cout << "enter BitLen ";
	cin >> n;
	bf = TBitField(n);
	cout << "enter bit field, if the end of the the enter -1" << endl;
	while (1)
	{
		cin >> b;
		if (b!=-1)
		{
			bf.SetBit(b);
		}
		else
		{
			break;
		}
	}
	return ist;
}

ostream &operator<<(ostream &ost, const TBitField &bf)
{
	for (int i = 0; i < bf.BitLen;i++)
	{
		cout << bf.GetBit(i);
	}
	return ost;
}

TBitField::~TBitField()
{
	delete pMem;
}
