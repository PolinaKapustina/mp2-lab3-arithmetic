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
	int size;
	int count;
	int head;
	T* stack;
public:

	TStack(int _size)
	{
		if ((_size < 1) || (_size > MaxStackSize)) throw ("razmer");
		head = -1;
		size = _size;
		stack = new T[size];
	}
	~TStack()
	{
		delete[] stack;
	}

	bool TStack<T>::IsEmpty() // �������� �� �������
	{
		if (head == -1)
			return true;
		else
			return false;
	}

	bool TStack<T>::IsFull() // - �������� �� �������
	{
		if (head == (size - 1))
			return true;
		else
			return false;
	}

	T TStack<T>::Pop() // ���������� ��������
	{
		if (IsEmpty() == 1)
			throw "Stack is Empty";
		else
		{
			T result = stack[head--];
			head--;
			return result;
		}
	}
	T TStack<T>::GetHeadElement() // �������� �������� �������� ��� ���������
	{
		if (IsEmpty()==1)
		{
			throw "Stack is Empty";
		}
		return stack[head];
	}

	int TStack<T>::Get() // ��������� ���������� ��������� � �����
	{
		return head++;
	}

	void Push(T elem) // ������� ��������
	{
		if (head + 1 == size)
		{
			size = size * 2;
			T* temp = new T[size];
			for (int i = 0; i < size/2; i++)
				temp[i] = stack[i];
			delete[] stack;
			stack = temp;
		}
		stack[head + 1] = elem;
		head++;
	}

	void Clear() // ������� �����
	{
		head = -1;
		delete[] stack;
		stack = new T[size];
	}

};


