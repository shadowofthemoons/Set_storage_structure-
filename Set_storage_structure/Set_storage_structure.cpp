

#include "pch.h"
#include "BitField.h"
#include <iostream>
using namespace std;

int main()
{
	TBitField g(10),h(1),f(3);
	cin >> g>>h;
	f = g | h;
	cout << f << endl;
	f = g & h;
	cout << f<< endl;
	cout << ~f << endl;
	



}

