#pragma once
class Stack
{
private:
	static constexpr int DEFAULT_CAPACITY = 16;
	int* stack;
	size_t size;
	size_t capacity;

	void copyFrom(const Stack& other);
	void free();
	void resize(const size_t newCapacity);

public:
	Stack();

	~Stack();

	explicit Stack(size_t initialCapacity);

	Stack(const Stack& other);

	Stack& operator=(const Stack& other);

	void push(int a);

	int pop();

	int peek()const;
};

