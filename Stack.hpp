#pragma once
#include<iostream>
#include<print>

template<typename T,size_t N>
class Stack
{
private:
	T arr[N];
	size_t count = 0;

public:
	Stack();

	void push(const T& a);
	T pop ();
	const T& peek()const;

	bool isEmpty()const;
	size_t getSize()const;
};

template<typename T,size_t N>
Stack<T,N>::Stack():count(0){}

template<typename T,size_t N>
void Stack<T,N>::push(const T& a)
{
	if (count >= N)
	{
		std::println("Stack overflow!");
		return;
	}
	arr[count++] = a;
}

template<typename T,size_t N>
T Stack<T, N>::pop()
{
	if (isEmpty())
	{
		std::println("The stack is empty!");
		return T();
	}
	return arr[--count];
}

template<typename T,size_t N>
const T& Stack<T, N>::peek()const
{
	if (isEmpty())
	{
		std::println("The stack is empty!");
		static T dummy{};
		return dummy;
	}
	return arr[count - 1];
}

template<typename T,size_t N>
size_t Stack<T, N>::getSize()const
{
	return count;
}

template<typename T,size_t N>
bool Stack<T, N>::isEmpty()const
{
	return count == 0;
}

