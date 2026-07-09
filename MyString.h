#pragma once
#include<fstream>

class MyString
{
private:
	static constexpr size_t MAX_CAPACITY = 1;
	char* string = nullptr;
	size_t size = 0;
	size_t capacity = MAX_CAPACITY;

	void copyFrom(const MyString& other);
	void free();
public:
	MyString();
	MyString(const char* string);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	~MyString();

	void setString(const char* string);
	size_t getSize()const;
	size_t getCapacity()const;
	MyString getSubstr(size_t start, size_t len)const;
	const char* c_str()const;

	MyString& operator+=(const MyString& other);
	const char& operator[](size_t index)const;
	char& operator[](size_t index);

	bool checkIndex(size_t index)const;

	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

	//Part 2
	std::strong_ordering operator<=>(const MyString& other)const;
};

MyString operator+(const MyString& lhs, const MyString& rhs);

//Part 1
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);