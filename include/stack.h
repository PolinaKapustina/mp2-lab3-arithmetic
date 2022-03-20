// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, +
// - ���������� ��������, +
// - �������� �������� �������� (��� ��������) +
// - �������� �� �������, +
// - ��������� ���������� ��������� � ����� +
// - ������� ����� +
// ��� ������� � ������ ���� ������ �������������� ������ +
#pragma once
#include <iostream>
#include <cstdlib>
#define MaxStackSize 100

template <class T>
class TStack
{
private:
	int size; // ������ �����
	int head; // ������� ������� �����
	int count; // ���������� ��������� � �����
	T* stack;
public:

	TStack(int size = 10) // - �����������
	{
		if (size <= 0 || size >= MaxStackSize)
		{
			throw "negative or zero size";
		}
		else
		{
			stack = new T[size];
			this->size = size;
			count = 0;
			head = -1;
		}
	}

	bool IsEmpty() // - �������� �� �������
	{
		if (head == -1)
			return true;
		else
			return false;
	}

	bool IsFull() // - �������� �� �������
	{
		if (head == (size - 1))
			return true;
		else
			return false;
	}

	void Push(T& Elem) // - ������� ��������
	{
		if (IsFull())
		{
			stack = (T*)realloc(stack, (size + 1) * sizeof(T));
		}
		stack[++head] = Elem;
		count++;
	}

	T Pop() // - ���������� ��������
	{
		if (IsEmpty())
		{
			throw "Can't pop out of empty stack";
		}
		else
		{
			T result = stack[head--];
			count--;
			return result;
		}
	}

	T GetHeadElement() // - �������� �������� �������� (��� ��������)
	{
		if (IsEmpty())
		{
			throw "stack is empty";
		}
		else
		{
			return stack[head];
		}
	}

	int Get() // - ��������� ���������� ��������� � �����
	{
		return count;
	}

	void Clear() // - ������� �����
	{
		head = -1;
		delete[] stack;
		stack = new T[size];
	}

	~TStack() // - ����������
	{
		delete[] stack;
	}
};


