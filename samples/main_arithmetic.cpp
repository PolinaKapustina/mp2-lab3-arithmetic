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
	cin >> s;
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	cout << "Polish notation:" << endl;
	v.PrintPolishNotation();
	res = v.PolishNotationCalculate();
	cout << endl << "Result:" << endl << res << endl;
}
