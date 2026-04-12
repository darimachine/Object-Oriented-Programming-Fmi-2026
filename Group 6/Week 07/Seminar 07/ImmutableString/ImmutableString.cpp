#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ImmutableString.h"

StringPool ImmutableString::pool;


void ImmutableString::free()
{
	pool.removeString(data);
}

void ImmutableString::copyFrom(const ImmutableString& other)
{
	data = pool.getString(other.data);
	size = strlen(data);
}

ImmutableString::ImmutableString(const char* text)
{
	data = pool.getString(text);
	size = strlen(data);
}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	copyFrom(other);
}

ImmutableString& ImmutableString::operator=(const ImmutableString& other)
{

	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

char ImmutableString::operator[](int index) const
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}

const char* ImmutableString::c_str() const
{
	return data;
}

int ImmutableString::getSize() const
{
	return size;
}

int ImmutableString::getRefCount() const
{
	
	return pool.getRefCount(data);
}

void ImmutableString::print()
{
	pool.print();
}


ImmutableString::~ImmutableString()
{
	free();
}

bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return lhs.data==rhs.data;
}

ostream& operator<<(std::ostream& os, const ImmutableString& im)
{
	os << im.data;
	return os;
}

ImmutableString operator+(const ImmutableString& lhs, const ImmutableString& rhs)
{
	
	char* temp = new char[lhs.getSize() + rhs.getSize() + 1];
	strcpy(temp, lhs.c_str());
	strcat(temp, rhs.c_str());
	ImmutableString result(temp);
	delete[] temp;
	return result;
}

bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return !(lhs==rhs);
}

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(),rhs.c_str())<0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
