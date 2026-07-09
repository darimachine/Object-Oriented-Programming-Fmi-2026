#include "MyString.h"
#include <cstring>
#include <iostream>

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new char[capacity];

	strcpy_s(data, capacity, other.data);
}

void MyString::free()
{
	delete[] data;
	data = nullptr;
}

void MyString::moveFrom(MyString&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;

	other.data = nullptr;
	other.size = 0;
	other.capacity = INITIAL_CAP;
}

void MyString::resize(size_t newCap)
{
	if (newCap <= capacity) {
		return;
	}

	char* temp = new char[newCap];

	if (data)
	{
		strcpy_s(temp, newCap, data);
	}
	else
	{
		temp[0] = '\0';
	}

	delete[] data;
	data = temp;
	capacity = newCap;
}

MyString::MyString() : size(0), capacity(INITIAL_CAP)
{
	data = new char[capacity];
	data[0] = '\0';
}

MyString::MyString(const char* data) :capacity(INITIAL_CAP), size(0)
{
	if (!data) {
		capacity = 1;
		this->data = new char[capacity];
		this->data[0] = '\0';
		return;
	}

	size = strlen(data);
	capacity = size + 1;
	this->data = new char[capacity];

	strcpy_s(this->data, capacity, data);
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

MyString::~MyString()
{
	free();
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
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

const char* MyString::c_str() const
{
	return data;
}

MyString MyString::substr(size_t start, size_t len) const
{
	if (start >= size) {
		return MyString("");
	}

	if (start + len > size) {
		len = size - start;
	}

	char* temp = new char[len + 1];

	for (size_t i = 0; i < len; i++)
	{
		temp[i] = data[start + i];
	}

	temp[len] = '\0';

	MyString result(temp);
	delete[] temp;

	return result;
}

MyString& MyString::insert(size_t index, char ch)
{
	if (index > size) {
		index = size;
	}
		

	if (size + 1 >= capacity) {
		resize(capacity * 2);
	}
		

	for (size_t i = size; i > index; --i) {
		data[i] = data[i - 1];
	}

	data[index] = ch;
	data[++size] = '\0';

	return *this;

}

MyString& MyString::insert(size_t index, const char* str)
{
	if (!str) {
		return *this;
	}          

	if (index > size) {
		index = size;
	}   

	size_t strLen = strlen(str);
	size_t newSize = size + strLen;

	if (newSize >= capacity) {
		
		size_t newCap = capacity;
		while (newCap <= newSize) {
			newCap *= 2;
		}
			
			
		char* newData = new char[newCap];

		
		for (size_t i = 0; i < index; ++i) {
			newData[i] = data[i];
		}
			
		for (size_t i = 0; i < strLen; ++i) {
			newData[index + i] = str[i];
		}
			
		for (size_t i = index; i < size; ++i) {
			newData[strLen + i] = data[i];
		}
			
		delete[] data;
		data = newData;
		capacity = newCap;
	}
	else {
	
		for (size_t i = size; i > index; --i) {
			data[i + strLen - 1] = data[i - 1];
		}
		
		for (size_t i = 0; i < strLen; ++i) {
			data[index + i] = str[i];
		}
	}

	size = newSize;
	data[size] = '\0'; 
	return *this;
}

MyString& MyString::insert(size_t index, const MyString& str)
{
	return insert(index, str.c_str());
}

MyString& MyString::erase(size_t index)
{
	if (index >= size) {
		return *this;
	}

	for (size_t i = index; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
	data[size] = '\0';

	return *this;
}

MyString& MyString::erase(size_t index, size_t count)
{
	if (index >= size) {
		return *this;
	}

	if (index + count > size) {
		count = size - index;
	}

	for (size_t i = index; i + count < size; i++)
	{
		data[i] = data[i + count];
	}

	size -= count;
	data[size] = '\0';

	return *this;

}

bool MyString::contains(char ch)
{
	for (size_t i = 0; i < size; i++)
	{
		if (data[i] == ch) {
			return true;
		}
	}

	return false;
}

bool MyString::contains(const char* str)
{
	if (!str) {
		return false;
	}

	size_t strLen = strlen(str);

	if (strLen > size) {
		return false;
	}

	for (size_t i = 0; i <= size-strLen; i++)
	{
		size_t j = 0;

		for (; j < strLen; j++)
		{
			if (data[i + j] != str[j]) {
				break;
			}
		}

		if (j == strLen) {
			return true;
		}
	}

	return false;
	

}

bool MyString::contains(const MyString& str)
{
	return contains(str.c_str());
}

char& MyString::operator[](size_t index)
{
	return data[index];
}

const char& MyString::operator[](size_t index) const
{
	return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newSize = size + other.size;

	if (newSize + 1 > capacity)
	{
		resize(newSize + 1);
	}

	for (size_t i = 0; i < other.size; i++)
	{
		data[size + i] = other.data[i];
	}

	size = newSize;
	data[size] = '\0';

	return *this;
}

std::strong_ordering MyString::operator<=>(const MyString& other) const
{

	int cmp = strcmp(data, other.data);

	if (cmp < 0) return std::strong_ordering::less;
	if (cmp > 0) return std::strong_ordering::greater;
	return std::strong_ordering::equal;

}


MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
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

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.c_str();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buffer[1024]; 
	is >> buffer;

	str = MyString(buffer); 
	return is;
}
