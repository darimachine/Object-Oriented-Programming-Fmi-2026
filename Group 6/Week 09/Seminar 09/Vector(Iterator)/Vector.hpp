#pragma once
#include <iostream>
#include <compare>
using namespace std;
template <typename T>
class Vector
{
	T* data = nullptr;
	int size = 0;
	int capacity = 8;

	void free();
	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector&& other) noexcept;
	void resize(int newCap);
public:

	class Iterator {
		T* ptr=nullptr;

	public:
		explicit Iterator(T* ptr) : ptr(ptr) {}

		T& operator*() const {
			return *ptr;
		}
		T* operator->() const {
			return ptr;
		}

		Iterator& operator++() {
			++ptr;
			return *this;
		}

		Iterator operator++(int dummy) {
			Iterator temp(*this);
			++(*this);
			return temp;
		}
		bool operator==(const Iterator& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const Iterator& other) const {
			return ptr != other.ptr;
		}
	};
	class ReverseIterator {
		T* ptr = nullptr;
	public:
		explicit ReverseIterator(T* ptr) : ptr(ptr) {}
		T& operator*() const {
			return *ptr;
		}
		T* operator->() const {
			return ptr;
		}
		ReverseIterator& operator++() {
			--ptr;
			return *this;
		}
		ReverseIterator operator++(int) {
			ReverseIterator temp(*this);
			++(*this);
			return temp;
		}

		bool operator==(const ReverseIterator& other) const {
			return ptr == other.ptr;
		}

		bool operator!=(const ReverseIterator& other) const {
			return ptr != other.ptr;
		}

	};

	class ConstIterator {
		const T* ptr = nullptr;

	public:
		explicit ConstIterator(T* ptr) : ptr(ptr) {}

		const T& operator*() const {
			return *ptr;
		}
		const T* operator->() const {
			return ptr;
		}

		ConstIterator& operator++() {
			++ptr;
			return *this;
		}

		ConstIterator operator++(int dummy) {
			ConstIterator temp(*this);
			++(*this);
			return temp;
		}
		bool operator==(const ConstIterator& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const ConstIterator& other) const {
			return ptr != other.ptr;
		}
	};
	Vector();
	explicit Vector(int capacity);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);

	Vector(Vector&& other) noexcept;
	Vector& operator=(Vector&& other) noexcept;

	~Vector();

	int getSize() const;
	int getCapacity() const;

	bool empty() const;

	void clear();

	T& operator[](size_t index);
	const T& operator[](size_t index) const;


	void push_back(const T& obj);
	void push_back(T&& obj);

	std::strong_ordering operator<=>(const Vector& other) const;

	friend ostream& operator<< <T>(ostream& os, const Vector<T>& obj);

	Iterator begin();
	Iterator end();

	ReverseIterator rbegin();
	ReverseIterator rend();

	ConstIterator cbegin() const;
	ConstIterator cend() const;
};
template<typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
	auto cmp = lhs <=> rhs;
	return cmp == 0;
}
template<typename T>
inline void Vector<T>::free()
{
	delete[] data;
}

template<typename T>
inline void Vector<T>::copyFrom(const Vector<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
inline void Vector<T>::moveFrom(Vector&& other) noexcept
{
	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;

	data = other.data;
	other.data = nullptr;
}
template<typename T>
bool Vector<T>::empty() const {
	return size == 0;
}

template<typename T>
void Vector<T>::clear() {
	size = 0;
}
template<typename T>
inline void Vector<T>::resize(int newCap)
{
	T* temp = new T[newCap];
	capacity = newCap;
	
	int elementsToMove = size < newCap ? size : newCap;
	for (int i = 0; i < elementsToMove; i++)
	{
		temp[i] = std::move(data[i]);
	}
	delete[] data;
	size = elementsToMove;
	data = temp;
}

template<typename T>
inline Vector<T>::Vector()
{
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(int capacity)
{
	this->capacity = capacity;
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	copyFrom(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
	// TODO: insert return statement here
}

template<typename T>
inline Vector<T>::Vector(Vector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
template<typename T>
inline void Vector<T>::push_back(const T& obj) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[size++] = obj;
}
template<typename T>
inline void Vector<T>::push_back(T&& obj) {
	if (size == capacity) {
		resize(capacity * 2);
	}
	data[size++] = std::move(obj);
}
template<typename T>
inline std::strong_ordering Vector<T>::operator<=>(const Vector& other) const
{
	int minSize = std::min(size, other.size);
	for (int i = 0; i < minSize; i++)
	{
		auto cmp = data[i] <=> other.data[i];
		if (cmp != 0) return cmp;
	}
	return size <=> other.size;
}
template<typename T>
T& Vector<T>::operator[](size_t index) {
	// validaciq
	return data[index];
}
template<typename T>
const T& Vector<T>::operator[](size_t index) const{
	// validaciq
	return data[index];
}
template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& obj) {
	for (int i = 0; i < obj.size; i++)
	{
		os << obj.data[i] << endl;
	}
	return os;
}
template<typename T>
inline Vector<T>::~Vector()
{
	free();
}

template<typename T>
inline int Vector<T>::getSize() const
{
	return size;
}

template<typename T>
inline int Vector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
Vector<T>::Iterator Vector<T>::begin() {
	return Iterator(data);
}
template<typename T>
Vector<T>::Iterator Vector<T>::end() {
	return Iterator(data + size);
}

template<typename T>
Vector<T>::ReverseIterator Vector<T>::rbegin() {
	return ReverseIterator(data+size-1);
}
template<typename T>
Vector<T>::ReverseIterator Vector<T>::rend() {
	return ReverseIterator(data-1);
}

template <typename T>
Vector<T>::ConstIterator Vector<T>::cbegin() const {
	return ConstIterator(data);
}

template <typename T>
Vector<T>::ConstIterator Vector<T>::cend() const {
	return ConstIterator(data + size);
}


