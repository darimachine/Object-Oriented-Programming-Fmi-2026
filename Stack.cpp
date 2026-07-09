#include "Stack.h"
#include<iostream>
#include<print>

void Stack::copyFrom(const Stack& other)
{
	size = other.size;
	capacity = other.capacity;

	stack = new int[capacity];

	size_t elementsToCopy = (size < capacity) ? size : capacity;

	for (size_t i = 0; i < elementsToCopy; i++)
	{
		stack[i] = other.stack[i];
	}

	
}

void Stack::free()
{
	delete[] stack;
	stack = nullptr;
}

void Stack::resize(size_t newCap)
{
	int* resized = new int[newCap];

	size_t elementsToCopy = (size < newCap) ? size : newCap;

	for (size_t i = 0; i < elementsToCopy; i++)
	{
		resized[i] = stack[i];
	}

	delete[] stack;

	stack = resized;
	capacity = newCap;
	size = elementsToCopy;
}

Stack::Stack() :size(0), capacity(DEFAULT_CAPACITY)
{
	stack = new int[capacity];
}

Stack::Stack(int* arr, size_t size, size_t capacity):size(size), capacity(capacity)	
{
	this->stack = new int[capacity];

	size_t elementsToCopy = (size < capacity) ? size : capacity;

	for (size_t i = 0; i < elementsToCopy; i++) {
		stack[i] = arr[i];
	}
}

Stack::Stack(const Stack&other)
{
	copyFrom(other);
}

Stack& Stack::operator=(const Stack&other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Stack::~Stack()
{
	free();
}

void Stack::push(int number)
{
	if (size >= capacity) {
		if (capacity == 0) {
			resize(1);
		}
		else {
			resize(capacity * 2);
		}
	}

	stack[size++] = number;
}

int Stack::pop()
{
	if (size == 0) {
		std::println("Stack is empty");
	}

	int result = stack[size - 1];
	size--;

	return result;
	
}

int Stack::peek()const
{
	if (size == 0) {
		std::println("Stack is empty!");
	}
	return stack[size-1];
}

