#include "Stack.h"

Stack::Stack() :Stack(DEFAULT_CAPACITY){}

Stack::~Stack()
{
	delete[]stack;
}

Stack::Stack(const Stack& other)
{
	copyFrom(other);
}

void Stack::copyFrom(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;
	stack = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		stack[i] = other.stack[i];
	}
}

void Stack::free()
{
	delete[]stack;
	stack = nullptr;
	size = 0;
	capacity = 0;
}

Stack& Stack::operator=(const Stack& other)
{
	if (this == &other)
	{
		return *this;
	}

	free();
	copyFrom(other);

	return *this;
}

explicit Stack::Stack(size_t initialCapacity) :capacity(initialCapacity),size(0)
{
	stack = new int[capacity];
}

void Stack::push(int a)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	stack[size] = a;
	size++;
}

int Stack::pop()
{
	if (size == 0)
	{
		return 0;
	}

	int last = stack[size-1];

	size--;
	return last;
}

int Stack::peek()const
{
	if (size == 0)
	{
		return 0;
	}

	return stack[size-1];
}

void Stack::resize(const size_t newCapacity)
{
	int* newStack = new int[newCapacity];

	for (size_t i = 0;i < capacity;i++)
	{
		newStack[i] = stack[i];
	}

	delete[]stack;
	stack = newStack;
	capacity = newCapacity;
}
