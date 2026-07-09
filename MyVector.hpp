#pragma once
#include<iostream>
#include<print>
#include<utility>

template<typename T>
class MyVector
{
private:
	static constexpr size_t DEFAULT_CAPACITY = 8;
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const MyVector<T>& other);
	void moveFrom(MyVector<T>&& other);
	void free();
	void resize(size_t newCapacity);
	bool checkIndex(size_t index)const;
	bool checkInsertIndex(size_t index)const;

public:
	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T& element);

	MyVector(const MyVector<T>& other);
	MyVector& operator=(const MyVector<T>& other);
	MyVector(MyVector<T>&& other)noexcept;
	MyVector& operator=(MyVector<T>&& other)noexcept;
	~MyVector();

	T& operator[](size_t index);
	const T& operator[](size_t index)const;

	void push_back(const T& element);
	void push_back(T&& element);
	void pop_back();

	bool isEmpty()const;
	void insert(size_t index, const T& element);
	void insert(size_t index, T&& element);
	void erase(size_t index);
	void shrinkToFit();
	void clear();

	T& front();
	const T& front()const;
	T& back();
	const T& back()const;

	size_t getSize()const;
	size_t getCapacity()const;

	const T* getData()const;

	void sort();
	void print()const;
};

template<typename T>
MyVector<T>::MyVector():size(0),capacity(DEFAULT_CAPACITY)
{
	data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(size_t n):size(n),capacity(n)
{
	data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(size_t n, const T& element) : size(n),capacity(n)
{
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = element;
    }
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	T* tmp = new T[other.capacity];
	for (size_t i = 0;i < other.size;i++)
	{
		tmp[i] = other.data[i];
	}

	delete[]data;
	data = tmp;
	size = other.size;
	capacity = other.capacity;
}

template<typename T>
void MyVector<T>::moveFrom(MyVector<T>&& other)
{
	data = other.data;
	size = other.size;
	capacity = other.capacity;

	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template<typename T>
void MyVector<T>::free()
{
	delete[]data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector<T>&& other)noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
void MyVector<T>::resize(size_t newCapacity)
{
	T* tmp = new T[newCapacity];
	size_t newSize = std::min(size, newCapacity);

	for (size_t i = 0;i < newSize;i++)
	{
		tmp[i] = std::move(data[i]);
	}
	delete[]data;
	data = tmp;
	size = newSize;
	capacity = newCapacity;
}

template<typename T>
bool MyVector<T>::checkIndex(size_t index)const
{
	return index < size;
}

template<typename T>
bool MyVector<T>::checkInsertIndex(size_t index)const
{
	return index <= size;
}

template<typename T>
T& MyVector<T>::operator[](size_t index)
{
	if (!checkIndex(index))
	{
		std::println("Out of range!");
		static T dummy{};
		return dummy;
	}
	return data[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index)const
{
	if (!checkIndex(index))
	{
		std::println("Out of range!");
		static T dummy{};
		return dummy;
	}
	return data[index];
}

template<typename T>
void MyVector<T>::push_back(const T& element)
{
	if (size == capacity)
	{
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	data[size++] = element;
}

template<typename T>
void MyVector<T>::push_back(T&& element)
{
	if (size == capacity)
	{
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	data[size++] = std::move(element);
}

template<typename T>
bool MyVector<T>::isEmpty()const
{
	return size == 0;
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (isEmpty())
	{
		std::println("The vector is empty!");
		return;
	}
	--size;
}

template<typename T>
void MyVector<T>::insert(size_t index, const T& element)
{
	if (!checkInsertIndex(index))
	{
		return;
	}
	if (size == capacity)
	{
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	for (size_t i = size;i > index;--i)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	size++;
}

template<typename T>
void MyVector<T>::insert(size_t index, T&& element)
{
	if (!checkInsertIndex(index))
	{
		return;
	}
	if (size == capacity)
	{
		resize(capacity == 0 ? 1 : capacity * 2);
	}
	for (size_t i = size;i > index;--i)
	{
		data[i] = std::move(data[i - 1]);
	}
	data[index] = std::move(element);
	size++;
}

template<typename T>
void MyVector<T>::erase(size_t index)
{
	if (!checkIndex(index))
	{
		return;
	}
	for (size_t i = index; i < size - 1; i++)
	{
		data[i] = std::move(data[i + 1]);
	}
	size--;
}

template<typename T>
void MyVector<T>::clear()
{
	size = 0;
}

template<typename T>
void MyVector<T>::shrinkToFit()
{
	if (size == capacity || size == 0)
	{
		return;
	}
	resize(size);
}

template<typename T>
T& MyVector<T>::front()
{
	return data[0];
}

template<typename T>
const T& MyVector<T>::front()const
{
	return data[0];
}

template<typename T>
T& MyVector<T>::back()
{
	return data[size - 1];
}

template<typename T>
const T& MyVector<T>::back()const
{
	return data[size - 1];
}

template<typename T>
size_t MyVector<T>::getSize()const
{
	return size;
}

template<typename T>
size_t MyVector<T>::getCapacity()const
{
	return capacity;
}

template<typename T>
const T* MyVector<T>::getData()const
{
	return data;
}

template<typename T>
void MyVector<T>::sort()
{
	for (size_t i = 0;i < size;i++)
	{
		size_t minIndex = i;
		for (size_t j = i+1;j < size;j++)
		{
			if (data[j] < data[minIndex])
			{
				minIndex = j;
			}
		}
		if (i != minIndex)
		{
			std::swap(data[i], data[minIndex]);
		}
	}
}

template<>
void MyVector<unsigned char>::sort()
{
	int count[256]{ 0 };
	for (size_t i = 0;i < size;i++)
	{
		count[data[i]]++;
	}

	size_t index = 0;
	for (size_t i = 0;i < 256;i++)
	{
		while (count[i]--)
		{
			data[index++] = (unsigned char)i;
		}
	}
}

template<typename T>
void MyVector<T>::print()const
{
	for (size_t i = 0;i < size;i++)
	{
		std::print("{} ", data[i]);
	}
	std::println();
}