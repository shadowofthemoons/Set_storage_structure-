#include "pch.h"
#include "Set.h"
#include "BitField.h"
#include <iostream>
using namespace std;

TSet::TSet(int mp) :BitField(mp)
{
	MaxPower = mp;
}

TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

int TSet::GetMaxPower(void) const
{
	return (MaxPower);
}

void TSet::InsElem(const int n)
{
	BitField.SetBit(n);
}

void TSet::DelElem(const int n)
{
	BitField.ClrBit(n);
}

int TSet::IsMember(const int n) const
{
	return(BitField.GetBit(n));
}


int TSet:: operator== (const TSet &s)
{
	if (BitField == s.BitField)
	{
		return (1);
	}
	return (0);
}

TSet& TSet:: operator=(const TSet &s)
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;
}

TSet TSet:: operator+ (const int n)
{
	BitField.SetBit(n);
	return *this;
}
TSet TSet:: operator- (const int n)
{
	BitField.ClrBit(n);
	return *this;
}

TSet TSet:: operator+ (const TSet &s)
{
	if (s.MaxPower > MaxPower)
	{
		MaxPower = s.MaxPower;
	}
	BitField = BitField | s.BitField;
	return *this;
}

TSet TSet:: operator * (const TSet &s)
{
	if (s.MaxPower < MaxPower)
	{
		MaxPower = s.MaxPower;
	}
	BitField = BitField & s.BitField;
	return *this;
}

TSet TSet:: operator~ (void)
{
	BitField = ~BitField;
	return *this;
}

istream &operator>>(istream &istr, TSet &bf)
{
	istr >> bf.BitField;
	bf.MaxPower = bf.BitField.GetLength();
	return (istr);
}
ostream &operator<<(ostream &ostr, const TSet &bf)
{
	int i;
	ostr << endl << "to output as a bit field, enter 1, and if as a set, enter 2" << endl;
	cin >> i;
	if (i == 1)
	{
		ostr << bf.BitField;
	}
	else
	{
		for (i = 0; i < bf.MaxPower; i++)
		{
			if (bf.IsMember(i))
			{
				ostr << i << ' ';
			}
		}
		ostr << endl;
	}
	return (ostr);
}

TSet::~TSet()
{
}
