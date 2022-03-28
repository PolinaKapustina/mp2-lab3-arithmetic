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
	while (chet == 0)
	{
		chet = -1;
		cin >> s;
		PolishNotation v(s);
		try
		{
			v.TranslationToPolishNotation();
			v.PolishNotationCalculate();
		}
		catch (int)
		{
			cout << "The expression contains errors. Type it again." << endl;
			chet = 0;
		}
		if (chet == -1)
		{
			cout << "Polish notation:" << endl;
			v.PrintPolishNotation();
			res = v.PolishNotationCalculate();
			cout << endl << "Result:" << endl << res << endl;
			cout << "Would you like to calculate a new expression? Yes or no?" << endl;
			string str;
			int k = 0;
			while (k == 0)
			{
				cin >> str;
				if (str == "yes" || str == "Yes" || str == "YES")
				{
					cout << "Enter your expression, no spaces." << endl;
					cout << "Allowed symbols: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, x, y, z, ., /, *, -, +" << endl;
					chet = 0;
					k = -1;
				}
				else
				{
					if (str == "NO" || str == "No" || str == "no")
						k = -1;
					else
						cout << "It seems you made a mistake in your answer. Enter the answer again, it must be 'yes' or 'no'." << endl;
				}
			}
		}
	}
}
