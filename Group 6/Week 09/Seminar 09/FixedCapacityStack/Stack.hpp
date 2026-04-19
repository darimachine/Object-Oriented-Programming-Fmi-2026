#include <iostream>
using namespace std;

template <class T, const unsigned S>
class Stack {

private:
	T arr[S];
	size_t size = 0;

public:

	void push(const T& obj);
	void push(T&& obj);

	void pop();
	const T& peek() const;
	const size_t getSize() const;
	bool isEmpty() const;
	bool isFull() const;
};

template<class T, unsigned S>
void Stack<T, S>::push(const T& obj)
{
	if (isFull()) {
		return; //throw 
	}
	arr[size++] = obj;
	//size++;
}

template<class T, unsigned S>
void Stack<T, S>::push(T&& obj)
{
	if (isFull()) {
		return; //throw 
	}
	arr[size++] = std::move(obj);
}

template<class T, unsigned S>
void Stack<T, S>::pop()
{
	if (isEmpty()) {
		throw std::out_of_range("Error");
	}
	size--;
}

template<class T, unsigned S>
const T& Stack<T, S>::peek() const
{
	if (isEmpty()) {
		throw std::out_of_range("stack is empty");
	}
	return arr[size - 1];
}

template<class T, unsigned S>
const size_t Stack<T, S>::getSize() const
{
	return size;
}

template<class T, unsigned S>
bool Stack<T, S>::isEmpty() const
{
	return size == 0;
}

template<class T, unsigned S>
bool Stack<T, S>::isFull() const
{
	return size == S;
}
