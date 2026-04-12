#include "MyString.h"
#include <cstring>
#pragma warning(disable: 4996)


std::istream& operator>>(istream& is, MyString& str)
{
	char buffer[1024];
	is >> buffer;
	size_t buffLength = strlen(buffer);
	if (buffLength > str.capacity) {
		str.resize(buffLength * 2);
	}

	strcpy(str.data, buffer);
	str.size = buffLength;

	return is;
}

std::ostream& operator<<(ostream& os, const MyString& str)
{
	os << str.data;
	return os;

}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString temp(lhs);
	temp += rhs;
	return temp;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str())==0;
}

std::strong_ordering MyString::operator<=>(const MyString& other) const
{
	return strcmp(data, other.data) <=> 0;
}

char& MyString::operator[](size_t index)
{
	// if index out of range handle the error
	return data[index];
}

const char& MyString::operator[](size_t index) const
{
	// if index out of range check it
	// Error Handling
	return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	if (size + other.size + 1 > capacity) {
		resize((size + other.size + 1) * 2);
	}
	strncat(data, other.data, other.size);
	size += other.size;

	return *this;
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
}

void MyString::copyFrom(const MyString& other)
{
	capacity = other.capacity;
	data = new char[capacity];
	size = other.size;
	strcpy(data, other.data);
}

size_t MyString::length() const {
	return size;
}

const char* MyString::c_str() const {
	return data;
}

void MyString::moveFrom(MyString&& other) noexcept
{
	data = other.data;
	other.data = nullptr;
	size = other.size;
	other.size = 0;
	capacity = other.capacity;
	other.capacity = 0;
}

void MyString::resize(size_t newCap)
{
	capacity = newCap;
	char* temp = new char[capacity];
	strcpy(temp, data);
	delete[] data;
	data = temp;

}

MyString::MyString()
{
	data = new char[capacity];
	data[0] = '\0';

}

MyString::MyString(const char* data)
{
	int len = strlen(data);
	capacity = len * 2;
	this->data = new char[capacity];
	strcpy(this->data, data);
	size = len;
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;

}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
	// TODO: insert return statement here
}

