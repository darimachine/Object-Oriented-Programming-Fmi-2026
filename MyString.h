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
	void moveFrom(MyString&&);

	void resize(size_t);

public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	~MyString();

	MyString(MyString&&) noexcept;
	MyString& operator=(MyString&&) noexcept;

	size_t getSize() const;
	size_t getCapacity() const;
	const char* c_str() const;

	MyString substr(size_t, size_t) const;

	MyString& insert(size_t, char);
	MyString& insert(size_t, const char*);
	MyString& insert(size_t, const MyString&);

	MyString& erase(size_t);
	MyString& erase(size_t, size_t);

	bool contains(char);
	bool contains(const char*);
	bool contains(const MyString&);

	char& operator[](size_t);
	const char& operator[](size_t) const;

	MyString& operator+=(const MyString&);

	std::strong_ordering operator<=>(const MyString&) const;
	
};

MyString operator+(const MyString&, const MyString&);

bool operator==(const MyString&, const MyString&);
bool operator<(const MyString&, const MyString&);

bool operator!=(const MyString&, const MyString&);
bool operator>(const MyString&, const MyString&);
bool operator<=(const MyString&, const MyString&);
bool operator>=(const MyString&, const MyString&);

std::ostream& operator<<(std::ostream&, const MyString&);
std::istream& operator>>(std::istream&, MyString&);
