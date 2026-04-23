#pragma once
#include<iostream>
#include<functional>
#include"MyVector.hpp"
#include"Optional.hpp"

template<typename T>
class Pipeline
{
private:
	T value;
	MyVector < std::function<T(T)>> ops;

public:
	Pipeline(const T& value);
	Pipeline<T>& pipe(const std::function<T(T)>& function);
	T execute();
	Optional<T> executeWhileTrue();
	const T& getValue()const;
};

template<typename T,class R>
Pipeline<R> transform(const Pipeline<T>& p, const std::function<R(T)>& function)
{
	R result = function(p.getValue());
	return Pipeline<R>(result);
}

template<typename T>
Pipeline<T>::Pipeline(const T& value):value(value){}

template<typename T>
Pipeline<T>& Pipeline<T>::pipe(const std::function<T(T)>& function)
{
	ops.push_back(function);
	return *this;
}

template<typename T>
T Pipeline<T>::execute()
{
	for (size_t i = 0;i < ops.getSize();i++)
	{
		value = ops[i](value);
	}
	ops.clear();
	return value;
}

template<typename T>
Optional<T> Pipeline<T>::executeWhileTrue()
{
	for (size_t i = 0;i < ops.getSize();i++)
	{
		value = ops[i](value);
		if (!value)
		{
			ops.clear();
			return Optional<T>();
		}
	}
	ops.clear();
	return Optional<T>(value);
}

template<typename T>
const T& Pipeline<T>::getValue()const
{
	return value;
}