#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include<cstring>
#include<iostream>
#include<print>

MyString::MyString() :size(0), capacity(MAX_CAPACITY)
{
	string = new char[capacity];
	string[0] = '\0';
}

MyString::MyString(const char* string)
{
	setString(string);
}

void MyString::setString(const char* string)
{
	if (string == nullptr)
	{
		return;
	}
	delete[] this->string;
	this->string = nullptr;

	size = strlen(string);
	capacity = size + 1;

	this->string = new char[capacity];
	strcpy(this->string, string);
}

void MyString::copyFrom(const MyString& other)
{
	setString(other.string);
}

void MyString::free()
{
	delete[]string;
	string = nullptr;
	size = 0;
	capacity = 0;
}

MyString::~MyString()
{
	free();
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

size_t MyString::getSize()const
{
	return size;
}

size_t MyString::getCapacity()const
{
	return capacity;
}

MyString MyString::getSubstr(size_t start, size_t len)const
{
	if (start >= size || start + len > size)
	{
		return MyString();
	}

	char* substr = new char[len + 1];
	for (size_t i = 0; i < len; i++)
	{
		substr[i] = string[start + i];
	}
	substr[len] = '\0';

	MyString result(substr);
	delete[]substr;
	substr = nullptr;

	return result;
}

const char* MyString::c_str()const
{
	return string;
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newSize = size + other.size;
	size = newSize;
	capacity = newSize + 1;
	char* result = new char[capacity];

	strcpy(result, string);
	strcat(result, other.string);

	delete[] string;
	string = result;
	
	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool MyString::checkIndex(size_t index)const
{
	if (index >= size)
	{
		std::println("Index out of range!");
		return false;
	}
	return true;
}

char& MyString::operator[](size_t index)
{
	if (!checkIndex(index))
	{
		return string[0];
	}

	return string[index];
}

const char& MyString::operator[](size_t index)const
{
	if (!checkIndex(index))
	{
		return string[0];
	}
	return string[index];
}

std::istream& operator>>(std::istream& is, MyString& string)
{
	char buffer[1024];
	is.getline(buffer, 1024);
	string.setString(buffer);
	return is;
}

std::ostream& operator<<(std::ostream& os, const MyString& string)
{
	os << string.c_str();
	return os;
}

//Part 1
bool operator==(const MyString& lhs, const MyString& rhs)
{
	if (lhs.getSize() != rhs.getSize())
	{
		return false;
	}

	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return rhs < lhs;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs < rhs);
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

//Part 2
std::strong_ordering MyString::operator<=>(const MyString& other)const
{
	int cmp = strcmp(string, other.string);
	return cmp <=> 0;
}
