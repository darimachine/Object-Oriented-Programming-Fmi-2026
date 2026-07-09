#include "MyString.h"
#include <cstring>

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

MyString::MyString(): size(0), capacity(INITIAL_CAP)
{
	data = new char[capacity];
	data[0] = '\0';
}

MyString::MyString(const char*data):capacity(INITIAL_CAP), size(0)
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

MyString& MyString::operator=(const MyString&other)
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

char MyString::operator[](size_t index)
{
	return data[index];
}

const char MyString::operator[](size_t index) const
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

std::ostream& operator<<(std::ostream& of, const MyString& str)
{
	for (size_t i = 0; i < str.size; i++)
	{
		of << str[i];
	}

	return of;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buffer[1024];
	is >> buffer;

	str = MyString(buffer);

	return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) == 0) {
		return true;
	}

	return false;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	if (strcmp(lhs.c_str(), rhs.c_str()) < 0) {
		return true;
	}

	return false;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return rhs<lhs;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs<rhs);
}
