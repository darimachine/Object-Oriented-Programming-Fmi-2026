
#pragma once
#include <iostream>
#include <compare>
using namespace std;
class MyString
{
private:
	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 8;

	void free();
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other) noexcept;

	void resize(size_t newCap);

public:
	MyString();
	MyString(const char* data);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	size_t length() const;

	const char* c_str() const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	MyString& operator+=(const MyString& other);

	std::strong_ordering operator<=>(const MyString& str) const;

	friend std::istream& operator>>(istream& is, MyString& str);
	friend std::ostream& operator<<(ostream& os, const MyString& str);
};
MyString operator+(const MyString& lhs, const MyString& rhs);

bool operator==(const MyString& lhs, const MyString& rhs);



