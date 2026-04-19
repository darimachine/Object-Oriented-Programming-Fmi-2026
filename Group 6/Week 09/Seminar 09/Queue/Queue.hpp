#pragma once
#include <iostream>

template <typename T>
class Queue {
public:
	Queue();
	explicit Queue(size_t capacity);
	Queue(const Queue<T>& other);
	Queue(Queue<T>&& other) noexcept;

	Queue& operator=(const Queue<T>& other);
	Queue& operator=(Queue<T>&& other) noexcept;

	void push(const T& obj);
	void push(T&& obj);

	void pop();

	const T& peek() const;
	size_t getSize() const;
	bool isEmpty() const;

	~Queue();

private:
	T* arr = nullptr;
	size_t size = 0;
	size_t capacity = 8;

	// we will use circular buffer, so we need to know where the first element of the queue is
	// and where the next free place is
	size_t get = 0;
	size_t put = 0;

	void free();
	void copyFrom(const Queue<T>& other);
	void moveFrom(Queue<T>&& other);

	void resize(size_t newCap);
};

template <typename T>
void Queue<T>::free() {
	delete[] arr;
	arr = nullptr;
}

template <typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	get = 0;
	put = size;
	arr = new T[capacity]{};
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[(other.get + i) % other.capacity];
	}
}

template <typename T>
void Queue<T>::moveFrom(Queue<T>&& other)
{
	put = other.put;
	size = other.size;
	capacity = other.capacity;
	get = other.get;
	other.get = other.put = other.size = other.capacity = 0;
	arr = other.arr;
	other.arr = nullptr;
}

template<typename T>
void Queue<T>::resize(size_t newCap)
{
	T* temp = new T[newCap];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[get];
		(++get) %= capacity;
	}
	delete[] arr;
	arr = temp;

	get = 0;
	put = size;
	capacity = newCap;
}

template<typename T>
Queue<T>::Queue() : Queue(8) {}

template <typename T>
Queue<T>::Queue(size_t capacity)
{
	this->capacity = capacity;
	arr = new T[capacity];
}

template <typename T>
Queue<T>::Queue(const Queue<T>& other)
{
	copyFrom(other);
}

template <typename T>
Queue<T>::Queue(Queue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;

}

template <typename T>
void Queue<T>::push(const T& obj)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}
	arr[put] = obj;
	/*if (put == capacity) {
		put = 0;
	}
	else {
		put++;
	}*/
	(++put) %= capacity; // circular buffer

	size++;
}

template <typename T>
void Queue<T>::push(T&& obj)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}
	arr[put] = std::move(obj);
	/*if (put == capacity) {
		put = 0;
	}
	else {
		put++;
	}*/
	(++put) %= capacity; // we do this for circular buffer

	size++;
}

template <typename T>
void Queue<T>::pop()
{
	if (isEmpty()) {
		throw std::out_of_range("Empty queue");
	}
	(++get) %= capacity; // circular buffer
	size--;
}

template <typename T>
const T& Queue<T>::peek() const
{
	if (isEmpty()) {
		throw std::out_of_range("Empty queue");
	}
	return arr[get];
}

template <typename T>
size_t Queue<T>::getSize() const
{
	return size;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return size==0;
}

template <typename T>
Queue<T>::~Queue()
{
	free();
}
