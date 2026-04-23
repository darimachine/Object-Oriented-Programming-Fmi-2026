#pragma once
#include<iostream>
#include<print>

template<typename T>
class Queue
{
private:
	T* arr = nullptr;
	size_t size = 0;
	size_t capacity = 16;

	size_t get = 0;
	size_t put = 0;

	void free();
	void copyFrom(const Queue<T>& other);
	void moveFrom(Queue<T>&& other);

	void resize(size_t newCap);

public:
	Queue();
	explicit Queue(size_t capacity);

	Queue(const Queue<T>& other);
	Queue& operator=(const Queue<T>& other);

	Queue(Queue<T>&& other) noexcept;
	Queue& operator=(Queue<T>&& other) noexcept;

	~Queue();

	void push(const T& object);
	void push(T&& object);

	void pop();

	const T& peek() const;
	size_t getSize() const;
	bool isEmpty() const;
};

template<typename T>
Queue<T>::Queue() :Queue(16) {}

template<typename T>
Queue<T>::Queue(size_t capacity)
{
	this->capacity = capacity;
	arr = new T[capacity];
}

template<typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	get = 0;
	put = size;
	arr = new T[capacity]{};
	for (int i = 0;i < size;i++)
	{
		arr = other.arr[(other.get + i) % other.capacity];
	}
}

template<typename T>
void Queue<T>::free()
{
	delete[]arr;
	arr = nullptr;
	capacity = 0;
	size = 0;
	get = 0;
	put = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
	copyFrom(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
void Queue<T>::moveFrom(Queue<T>&& other)
{
	put = other.put;
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	arr = other.arr;

	other.get = 0;
	other.put = 0;
	other.size = 0;
	other.capacity = 0;
	other.arr = nullptr;
}

template<typename T>
Queue<T>::Queue(Queue<T>&& other)noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
Queue<T>::~Queue()
{
	free();
}

template<typename T>
void Queue<T>::resize(size_t newCap)
{
	T* newArr = new T[newCap];
	for (int i = 0;i < size;i++)
	{
		newArr[i] = arr[get];
		(++get) %= capacity;
	}
	delete[]arr;
	arr = newArr;

	get = 0;
	put = size;
	capacity = newCap;
}

template<typename T>
void Queue<T>::push(const T& object)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}
	arr[put] = object;
	(++put) %= capacity;
	size++;
}

template<typename T>
void Queue<T>::push(T&& object)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}
	arr[put] = std::move(object);
	(++put) %= capacity;
	size++;
}

template<typename T>
bool Queue<T>::isEmpty()const
{
	return size == 0;
}

template<typename T>
void Queue<T>::pop()
{
	if (isEmpty())
	{
		std::println("The queue is empty!");
		return;
	}
	(++get) %= capacity;
	size--;
}

template<typename T>
const T& Queue<T>::peek()const
{
	if (isEmpty())
	{
		std::println("The queue is empty!");
		return arr[0];
	}
	return arr[get];
}

template<typename T>
size_t Queue<T>::getSize()const
{
	return size;
}