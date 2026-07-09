#pragma once
#include<iostream>
#include<utility>
#include <fstream>

template<typename K,typename V>
class Pair
{
private:
	K key;
	V value;

public:
	Pair() = default;
	Pair(const K& key, const V& value);

	void setKey(const K& key);
	void setValue(const V& value);

	const K& getKey()const;
	const V& getValue()const;

	void setValue(V&& value);
	void setKey(K&& key);

	friend std::ostream& operator<< <K,V>(std::ostream& os, const Pair<K, V>& pair);
	friend std::istream& operator>> <K,V>(std::istream& is, Pair<K, V>& pair);
};

template<typename K, typename V>
Pair<K, V>::Pair(const K& key, const V& value):key(key),value(value){}

template<typename K, typename V>
void Pair<K, V>::setKey(const K& key)
{
	this->key = key;
}

template <typename K, typename V>
void Pair<K, V>::setValue(const V& value) 
{
	this->value = value;
}

template <typename K, typename V>
const K& Pair<K, V>::getKey() const 
{
	return key;
}

template <typename K, typename V>
const V& Pair<K, V>::getValue() const 
{
	return value;
}

template <typename K, typename V>
void Pair<K, V>::setKey(K&& key) 
{
	this->key = std::move(key);
}

template <typename K, typename V>
void Pair<K, V>::setValue(V&& value) 
{
	this->value = std::move(value);
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
{
	os << "Key: " << pair.key << " Value: " << pair.value;
	return os;
}

template <typename K, typename V>
std::istream& operator>>(std::istream& is, Pair<K, V>& pair)
{
	is >> pair.key >> pair.value;
	return is;
}