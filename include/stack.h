// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, +
// - извлечение элемента, +
// - просмотр верхнего элемента (без удаления) +
// - проверка на пустоту, +
// - получение количества элементов в стеке +
// - очистка стека +
// при вставке в полный стек должна перевыделяться память +
#pragma once
#include <iostream>
#include <cstdlib>
#define MaxStackSize 100

template <class T>
class TStack
{
private:
	int size; // размер стэка
	int head; // верхний элемент стэка
	int count; // количество элементов в стэке
	T* stack;
public:

	TStack(int size = 10) // - конструктор
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

	bool IsEmpty() // - проверка на пустоту
	{
		if (head == -1)
			return true;
		else
			return false;
	}

	bool IsFull() // - проверка на полноту
	{
		if (head == (size - 1))
			return true;
		else
			return false;
	}

	void Push(T& Elem) // - вставка элемента
	{
		if (IsFull())
		{
			stack = (T*)realloc(stack, (size + 1) * sizeof(T));
		}
		stack[++head] = Elem;
		count++;
	}

	T Pop() // - извлечение элемента
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

	T GetHeadElement() // - просмотр верхнего элемента (без удаления)
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

	int Get() // - получение количества элементов в стеке
	{
		return count;
	}

	void Clear() // - очистка стека
	{
		head = -1;
		delete[] stack;
		stack = new T[size];
	}

	~TStack() // - деструктор
	{
		delete[] stack;
	}
};


