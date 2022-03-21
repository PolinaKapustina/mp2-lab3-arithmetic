// тесты для стека
#pragma once
#include "stack.h"
#include <gtest.h>
#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW( TStack<int> st(5));
}

TEST(TStack, cant_create_stack_with_wrong_length)
{
	ASSERT_ANY_THROW( TStack<int> st(0), st1(-1));
}

TEST(TStack, cant_create_stack_with_too_big_length)
{
	ASSERT_ANY_THROW( TStack<int> st(MaxStackSize + 1));
}


TEST(TStack, can_get_size_of_stack)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.Get());
}

TEST(TStack, can_push_elem_in_stack)
{
	TStack <int> s(2);
	int a = 5;
	s.Push(a);
	EXPECT_EQ(1, s.Get());
}


TEST(TStack, can_get_top_elem_in_stack)
{
	TStack<int> st(5);
	int a = 5;
	st.Push(a);
	EXPECT_EQ(a, st.GetHeadElement());
}

TEST(TStack, can_pop_elem_in_stack)
{
	TStack<int> st(5);
	int a = 5;
	st.Push(a);
	st.Pop();
	EXPECT_EQ(0, st.Get());
}