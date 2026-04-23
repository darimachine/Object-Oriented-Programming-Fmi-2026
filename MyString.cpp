#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include<cstring>
#include<iostream>
#include<print>

MyString::MyString() :size(0), capacity(16)
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

void MyString::moveFrom(MyString&& other)
{
	string = other.string;
	size = other.size;
	capacity = other.capacity;

	other.string = nullptr;
	other.size = 0;
	other.capacity = 0;
}

void MyString::resize()
{
	capacity *= 2;
	char* newString = new char[capacity];
	for (size_t i = 0;i < size;i++)
	{
		newString[i] = string[i];
	}

	newString[size] = '\0';
	delete[]string;
	string = newString;
}

MyString::MyString(MyString&& other)noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
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
	return os << string.c_str();
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
	return strcmp(string, other.string) <=> 0;
}


//Week 7

MyString& MyString::insert(size_t index, char ch)
{
	if (index > size)
	{
		return *this;
	}
	if (size+1 >= capacity)
	{
		resize();
	}

	for (size_t i = size; i > index; i--)
	{
		string[i] = string[i - 1];
	}

	string[index] = ch;
	size++;
	string[size] = '\0';

	return *this;
}

MyString& MyString::insert(size_t index, const char* str)
{
	if (index > size)
	{
		return *this;
	}

	size_t len = strlen(str);

	while (size + len >= capacity)
	{
		resize();
	}

	for (size_t i = size + len; i > index + len - 1; i--)
	{
		string[i] = string[i - len];
	}

	for (size_t i = 0; i < len; i++)
	{
		string[index + i] = str[i];
	}

	size += len;
	string[size] = '\0';

	return *this;
}

MyString& MyString::insert(size_t index, const MyString& str)
{
	return insert(index, str.string);
}

MyString& MyString::erase(size_t index)
{
	if (index >= size)
	{
		return *this;
	}

	for (size_t i = index;i < size - 1;i++)
	{
		string[i] = string[i + 1];
	}

	size--;
	string[size] = '\0';
	return *this;
}

MyString& MyString::erase(size_t index, size_t count)
{
	if (index >= size)
	{
		return *this;
	}

	if (index + count >= size)
	{
		count = size - index;
	}

	for (size_t i = index;i < size - count;i++)
	{
		string[i] = string[i + count];
	}

	size -= count;
	string[size] = '\0';
	return *this;
}

bool MyString::contains(char ch)const
{
	for (size_t i = 0;i < size;i++)
	{
		if(string[i]==ch)
		{
			return true;
		}
	}

	return false;
}

bool MyString::contains(const char* str)const
{
	size_t len = strlen(str);
	if (len > size)
	{
		return false;
	}

	for (size_t i = 0;i <= size - len;i++)
	{
		size_t j = 0;
		while (j < len && string[i + j] == str[j])
		{
			j++;
		}
		if (j == len)
		{
			return true;
		}
	}
	return false;
}

bool MyString::contains(const MyString& str)const
{
	return contains(str.string);
}
