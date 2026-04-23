#pragma once
#include <iostream>

template<class T>
class SharedPtr {

	T* data=nullptr;
	size_t* refCount = nullptr;

	void free();
	void copyFrom(const SharedPtr& other);
	void moveFrom(SharedPtr&& other);

public:
	SharedPtr() = default;
	SharedPtr(T* obj);
	
	SharedPtr(const SharedPtr& other);
	SharedPtr(SharedPtr&& other);
	
	SharedPtr& operator=(const SharedPtr& other);
	SharedPtr& operator=(SharedPtr&& other);

	const T* operator->() const;
	T* operator->();

	const T& operator*() const;
	T& operator*();

	void reset(T* obj=nullptr);

	size_t getRefCount() const;

	operator bool() const;

	~SharedPtr();
};

template<class T>
inline void SharedPtr<T>::free()
{
	if (data == nullptr && refCount == nullptr) {
		return;
	}
	(*refCount)--;
	if (*refCount == 0) {
		delete data;
		delete refCount;
		data = nullptr;
		refCount = nullptr;
	}
}

template<class T>
inline void SharedPtr<T>::copyFrom(const SharedPtr& other)
{
	data = other.data;
	refCount = other.refCount;
	if (refCount) {
		(*refCount)++;
	}
}

template<class T>
inline void SharedPtr<T>::moveFrom(SharedPtr&& other)
{
	data = other.data;
	other.data = nullptr;

	refCount = other.refCount;
	other.refCount = nullptr;
}

template<class T>
inline SharedPtr<T>::SharedPtr(T* obj) : data(obj)
{
	if (obj) {
		refCount = new size_t(1);
	}
}

template<class T>
inline SharedPtr<T>::SharedPtr(const SharedPtr& other)
{
	copyFrom(other);
}

template<class T>
inline SharedPtr<T>::SharedPtr(SharedPtr&& other)
{
	moveFrom(std::move(other));
}

template<class T>
inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
inline SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
inline const T* SharedPtr<T>::operator->() const
{
	return data;
}

template<class T>
inline T* SharedPtr<T>::operator->()
{
	return data;
}

template<class T>
inline const T& SharedPtr<T>::operator*() const
{
	if (data == nullptr) {
		throw std::invalid_argument("Error exception");
	}
	return *data;
}

template<class T>
inline T& SharedPtr<T>::operator*()
{
	if (data == nullptr) {
		throw std::invalid_argument("Error exception");
	}
	return *data;
}

template<class T>
inline void SharedPtr<T>::reset(T* obj)
{
	if (data == obj) {
		return;
	}
	free();
	if (obj) {
		data = obj;
		refCount = new size_t(1);
	}
	else {
		data = nullptr;
		refCount = nullptr;
	}
	
}

template<class T>
inline size_t SharedPtr<T>::getRefCount() const
{
	return *refCount;
}

template<class T>
inline SharedPtr<T>::operator bool() const
{
	return data != nullptr;
}

template<class T>
inline SharedPtr<T>::~SharedPtr()
{
	free();
}
