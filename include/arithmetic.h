// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "stack.h"

using namespace std;
struct Lexem
{
	int priority; // приоритетность 
	string type; // тип (число\операци€)
	string lexm; // лексема

	Lexem& operator = (const Lexem& other)
	{
		this->priority = other.priority;
		this->lexm = other.lexm;
		this->type = other.type;

		return *this;
	}
};

class PolishNotation
{
private:
	string formula; // выражение
	vector <Lexem> polish;//польска€ (постфиксна€) запись
	vector <Lexem> l;
public:
	PolishNotation(string s); // конструктор
	void CorrectionChecker(string s); // проверка корректности
	double BinaryCalculate(double a, double b, string s); // математические операции
	void TranslationToPolishNotation(); // польскка€ запись
	void PrintPolishNotation(); // вывод польской записи
	double PolishNotationCalculate();
};

