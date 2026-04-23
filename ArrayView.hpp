#pragma once
#include<iostream>
#include"MyVector.hpp"
#include<print>
#include<fstream>

template<typename T>
class ArrayView
{
private:
	const T* data = nullptr;
	size_t size = 0;

	bool checkIndex(size_t index)const;

public:
	ArrayView() = default;

	ArrayView(const T* arr, size_t size);
	ArrayView(const MyVector<T>& vector);

	ArrayView(const T* arr, size_t begin, size_t end);
	ArrayView(const MyVector<T>& vector, size_t begin, size_t end);

	const T& operator[](size_t index)const;
	size_t getSize()const;
	bool isEmpty()const;

	ArrayView<T> subArr(unsigned beginIndex);
	ArrayView<T> subArr(unsigned beginIndex, size_t index);

	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const ArrayView<U>& vector);
};

template<typename T>
ArrayView<T>::ArrayView(const T*arr,size_t size):data(arr),size(size){}

template<typename T>
ArrayView<T>::ArrayView(const MyVector<T>& vector)
{
	data = vector.getData();
	size = vector.getSize();
}

template<typename T>
ArrayView<T>::ArrayView(const T* arr, size_t begin, size_t end)
{
	if (begin > end)
	{
		std::println("Invalid range!");
		data = nullptr;
		size = 0;
		return;
	}

	size = end - begin;
	data = arr + begin;
}

template<typename T>
ArrayView<T>::ArrayView(const MyVector<T>& vector, size_t begin, size_t end)
{
	if (begin > end || end > vector.getSize())
	{
		std::println("Invalid range!");
		data = nullptr;
		size = 0;
		return;
	}

	size = end - begin;
	data = vector.getData() + begin;
}

template<typename T>
size_t ArrayView<T>::getSize()const
{
	return size;
}

template<typename T>
bool ArrayView<T>::isEmpty()const
{
	return size == 0;
}

template<typename T>
const T& ArrayView<T>::operator[](size_t index)const 
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
bool ArrayView<T>::checkIndex(size_t index)const
{
	return index < size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const ArrayView<T>& vector)
{
	for (size_t i = 0; i < vector.size; i++)
	{
		os << vector.data[i] << " ";
	}
	return os;
}

template<typename T>
ArrayView<T> ArrayView<T>::subArr(unsigned beginIndex)
{
	if (!checkIndex(beginIndex))
	{
		std::println("Out of range!");
		return ArrayView(data, 0);
	}
	return ArrayView(data + beginIndex, size - beginIndex);
}

template<typename T>
ArrayView<T> ArrayView<T>::subArr(unsigned beginIndex, size_t size)
{
	if (!checkIndex(beginIndex) || beginIndex + size > this->size)
	{
		std::println("Out of range!");
		return ArrayView(data, 0);
	}
	return ArrayView(data + beginIndex, size);
}