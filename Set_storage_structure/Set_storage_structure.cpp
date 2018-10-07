#include "pch.h"
#include "BitField.h"
#include "Set.h"
#include <iostream>
using namespace std;

int main()
{
	const int size = 38;
	TBitField bf(size), negBf(size), expNegBf(size);
	bf.SetBit(35);
	negBf = ~bf;

	for (int i = 0; i < size; i++)
		expNegBf.SetBit(i);
	expNegBf.ClrBit(35);
	if (negBf == negBf)
	{
		cout << "true" << endl;
	}
	cout << endl << negBf << endl << negBf;
	/*
	int l1, l2;
	cout << "enter len 1 ";
	cin >> l1;
	cout << "enter len 2 ";
	cin>> l2;
	TSet a(l1), b(l2),c(10),d(10);
	cin >> a >> b;
	c = a + b;
	cout << "c = a + b" << c << endl;
	c = a * b;
	cout << "c = a * b" << c << endl;
	c = ~c;
	cout << "c = ~c " << c << endl;
	d=d + 2 + +8;
	cout << d;
	*/
}


