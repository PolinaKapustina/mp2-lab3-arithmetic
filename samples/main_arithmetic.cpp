// реализация пользовательского приложения


#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "stack.h"
#include "arithmetic.h"
#pragma once

using namespace std;

int main()
{
	cout << "Enter your expression, no spaces." << endl;
	cout << "Allowed symbols: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, x, y, z, ., /, *, -, +" << endl;
	double res;
	string s;
	int chet = 0;
	PolishNotation v(0);
	while (chet == 0)
	{
		chet = -1;
		cin >> s;
		PolishNotation v(s);
		try
		{
			v.TranslationToPolishNotation();
		}
		catch (int)
		{
			cout << "The expression contains errors. Type it again." << endl;
			chet = 0;
		}
		try
		{
			v.PolishNotationCalculate();
		}
		catch (string str)
		{
			cout << str;
			cout << "The expression contains errors. Type it again." << endl;
			chet = 0;
		}
	}
	cout << "Polish notation:" << endl;
	v.PrintPolishNotation();
	res = v.PolishNotationCalculate();
	cout << endl << "Result:" << endl << res << endl;
}
