// ����� ��� ���������� �������������� ���������

#include <gtest.h>
#include "arithmetic.h"
#include <string>

TEST(PolishNotation, throws_when_has_more_closing_parenthesis_then_opening)
{
	std::string s = "()3.0-2.0*4)";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, the_number_of_parenthesis_is_equal_but_they_are_set_incorrectly)
{
	std::string s = "3.0-2.0)(*3";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_has_more_opening_parenthesis_then_closing)
{
	std::string s = "((3.0-2.0)*5";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_missed_operand_before_parenthesis)
{
	double a;
	std::string s = "7(3.0-2.0)*4";
	PolishNotation v(s);

	ASSERT_ANY_THROW(a = v.PolishNotationCalculate());
}

TEST(PolishNotation, throws_when_missed_operand_after_parenthesis)
{
	double a;
	std::string s = "7*(3.0+2.0)5";
	PolishNotation v(s);
	ASSERT_ANY_THROW(a = v.PolishNotationCalculate());
}

TEST(PolishNotation, throws_when_too_many_dots_in_one_operand)
{
	std::string s = "5.0.5+2.0*5";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_dot_is_the_last_symbol_of_operand)
{
	std::string s = "5.0.+2.0*5";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_dot_is_the_first_symbol_of_operand)
{
	std::string s = "5.0+.2.0*5";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_expression_has_invalid_symbol)
{
	std::string s = "5.0+2.0!5";
	PolishNotation v(s);

	ASSERT_ANY_THROW(v.TranslationToPolishNotation());
}

TEST(PolishNotation, throws_when_binary_operation_is_the_first_symbol_not_minus)
{
	double a;
	std::string s = "+3.0+2.0";
	PolishNotation v(s);

	ASSERT_ANY_THROW(a = v.PolishNotationCalculate());
}

TEST(PolishNotation, throws_when_operation_is_the_last_symbol)
{
	double a;
	std::string s = "3.0+2.0-";
	PolishNotation v(s);

	ASSERT_ANY_THROW(a = v.PolishNotationCalculate());
}

TEST(PolishNotation, can_add)
{
	double a, b = 5.88;
	std::string s = "3.0+2.88";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	a = v.PolishNotationCalculate();

	EXPECT_EQ(a, b);
}

TEST(PolishNotation, can_subtract)
{
	double a, b = 0.5;
	std::string s = "3-2.5";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	a = v.PolishNotationCalculate();

	EXPECT_EQ(a, b);
}

TEST(PolishNotation, can_multiply)
{
	double z, y = 11.0;
	std::string s = "5.0*2.2";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	z = v.PolishNotationCalculate();

	EXPECT_EQ(z, y);
}

TEST(PolishNotation, can_divide)
{
	double a, b = 2;
	std::string s = "2.2/1.1";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	a = v.PolishNotationCalculate();

	EXPECT_EQ(a, b);
}

TEST(PolishNotation, can_work_with_unary_minus)
{
	double a, b = -2.5;
	std::string s = "-2.5";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	a = v.PolishNotationCalculate();

	EXPECT_EQ(a, b);
}

TEST(PolishNotation, can_work_with_seveal_unary_minuses)
{
	double a, b = 2.5;
	std::string s = "--2.5";
	PolishNotation v(s);
	v.TranslationToPolishNotation();
	a = v.PolishNotationCalculate();

	EXPECT_EQ(a, b);
}