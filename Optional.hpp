#pragma once
#include<iostream>
#include<utility>
#include<functional>
#include<initializer_list>

template<typename T>

class Optional
{
private:
	T* value = nullptr;

	void copyFrom(const Optional<T>& other);
	void moveFrom(Optional<T>&& other);
	void free();

public:
	Optional() = default;
	Optional(const T& value);

	Optional(const Optional<T>& other);
	Optional& operator=(const Optional<T>& other);
	Optional(Optional<T>&& other)noexcept;
	Optional& operator=(Optional<T>&& other)noexcept;
	~Optional();

	bool hasValue()const;
	const T& getValue()const;
	void setValue(const T& value);
	void setValue(T&& newValue);
	void clear();

	void filterFirst(const std::function<bool(const T&)>& pred,
		const std::initializer_list<T>& args);

	void filterLast(const std::function<bool(const T&)>& pred,
		const std::initializer_list<T>& args);

	template<typename U>
	Optional<U> apply(const std::function<U(const T&)>& f) const;
};

template<typename T>
Optional<T>::Optional(const T& value)
{
	this->value = new T(value);
}

template<typename T>
void Optional<T>::copyFrom(const Optional<T>& other)
{
	value = other.hasValue() ? new T(*other.value) : nullptr;
}

template<typename T>
bool Optional<T>::hasValue()const
{
	return value;
}

template<typename T>
void Optional<T>::moveFrom(Optional<T>&& other)
{
	value = other.value;
	other.value = nullptr;
}

template<typename T>
void Optional<T>::free()
{
	delete value;
	value = nullptr;
}

template<typename T>
Optional<T>::~Optional()
{
	free();
}

template<typename T>
void Optional<T>::clear() 
{
	free();
}

template<typename T>
Optional<T>::Optional(const Optional<T>& other)
{
	copyFrom(other);
}

template<typename T>
Optional<T>& Optional<T>::operator=(const Optional<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
Optional<T>::Optional(Optional<T>&& other)noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Optional<T>& Optional<T>::operator=(Optional<T>&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
void Optional<T>::setValue(const T& value)
{
	if (hasValue())
	{
		*(this->value) = value;
	}
	else
	{
		this->value = new T(value);
	}
}

template<typename T>
void Optional<T>::setValue(T&& value) 
{
	if (hasValue()) {
		*(this->value) = std::move(value);
	}
	else {
		this->value = new T(std::move(value));
	}
}

template<typename T>
const T& Optional<T>::getValue()const
{
	return *value;
}

template<typename T>
template<typename U>
Optional<U> Optional<T>::apply(const std::function<U(const T&)>& f)const
{
	if (!hasValue())
	{
		return Optional<U>();
	}

	return Optional<U>(f(*value));
}

template<typename T>
void Optional<T>::filterFirst(const std::function<bool(const T&)>& pred,
	const std::initializer_list<T>& args)
{
	clear();

	size_t count = args.size();
	const T* dataPtr = args.begin();

	for (size_t i = 0; i < count; i++)
	{
		if (pred(dataPtr[i]))
		{
			setValue(dataPtr[i]);
			return;
		}
	}
}

template<typename T>
void Optional<T>::filterLast(const std::function<bool(const T&)>& pred,
	const std::initializer_list<T>& args)
{
	clear();

	size_t count = args.size();
	const T* dataPtr = args.begin();

	for (size_t i = count; i > 0; i--)
	{
		if (pred(dataPtr[i - 1]))
		{
			setValue(dataPtr[i - 1]);
			return;
		}
	}
}