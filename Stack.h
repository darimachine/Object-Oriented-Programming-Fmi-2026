#pragma once

class Stack
{
private:
	int* stack = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	static constexpr unsigned DEFAULT_CAPACITY = 20;

	void copyFrom(const Stack&);
	void free();
	void resize(size_t newCap);

public:
	Stack();
	Stack(int*, size_t, size_t);
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();

	void push(int);
	int pop();
	int peek()const;
};

