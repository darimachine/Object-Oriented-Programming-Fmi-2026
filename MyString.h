#pragma once
#include<fstream>

class MyString
{
private:
	char* string = nullptr;
	size_t size = 0;
	size_t capacity = 16;

	void copyFrom(const MyString& other);
	void free();
	void setString(const char* string);
	void moveFrom(MyString&& other);
	void resize();
public:
	MyString();
	MyString(const char* string);
	~MyString();

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

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

	//Week 7
	MyString(MyString&& other)noexcept;
	MyString& operator=(MyString&& other)noexcept;

	MyString& insert(size_t index, char ch);
	MyString& insert(size_t index, const char* str);
	MyString& insert(size_t index, const MyString& str);

	MyString& erase(size_t index);
	MyString& erase(size_t index, size_t count);

	bool contains(char ch)const;
	bool contains(const char* str)const;
	bool contains(const MyString& str)const;
};

MyString operator+(const MyString& lhs, const MyString& rhs);

//Part 1
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);