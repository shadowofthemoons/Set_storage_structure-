#include "pch.h"
#include "Set.h"
#include "BitField.h"
#include <iostream>
using namespace std;

TSet::TSet(int mp)
{
	MaxPower = mp;
	BitField = TBitField(mp);
}

TSet::TSet(const TSet &s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

TSet::TSet(const TBitField &bf)
{
	MaxPower = bf.GetLength();
	BitField = bf;
}

TSet::~TSet()
{
}