

#include "pch.h"
#include "BitField.h"
#include <iostream>
using namespace std;

int main()
{
	TBitField g(10);
	cin >> g;
	g.SetBit(2);
	g.ClrBit(1);
	g.SetBit(8);
	cout << g;
}

