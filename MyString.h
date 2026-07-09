#pragma once
#include <iostream>
#include <compare>

class MyString {
private:
	char* data = nullptr;
	size_t size;
	size_t capacity;
	static constexpr unsigned int INITIAL_CAP = 1024;

	void copyFrom(const MyString&);
	void free();

	void resize(size_t);

public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	~MyString();

	size_t getSize() const;
	size_t getCapacity() const;
	const char* c_str() const;

	MyString substr(size_t, size_t) const;

	char operator[](size_t);
	const char operator[](size_t) const;

	MyString& operator+=(const MyString&);

	std::strong_ordering operator<=>(const MyString&) const;

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);

};

MyString operator+(const MyString&, const MyString&);

bool operator==(const MyString&, const MyString&);
bool operator<(const MyString&, const MyString&);

bool operator!=(const MyString&, const MyString&);
bool operator>(const MyString&, const MyString&);
bool operator<=(const MyString&, const MyString&);
bool operator>=(const MyString&, const MyString&);