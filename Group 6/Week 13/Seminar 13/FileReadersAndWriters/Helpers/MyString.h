#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
class MyString
{
public:
    MyString();
    MyString(const char* data);

    MyString(const MyString& other);
    MyString& operator=(const MyString& other);

    MyString(MyString&& other) noexcept;
    MyString& operator=(MyString&& other) noexcept;

    ~MyString();

    size_t length() const;
    const char* c_str() const;

    MyString& operator+=(const MyString& other);

    char& operator[](size_t index);
    char operator[](size_t index) const;

    MyString substr(size_t from, size_t length) const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::istream& operator>>(std::istream& is, MyString& str);

private:
    explicit MyString(size_t stringLength);

    void resize(size_t newAllocatedDataCapacity);
    void free();
    void copyFrom(const MyString& other);
    void moveFrom(MyString&& other) noexcept;

    char* data = nullptr;
    size_t currentSize = 0;
    size_t allocatedDataCapacity = 0;
};

std::ostream& operator<<(std::ostream& os, const MyString& str);

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);

void swap(MyString& lhs, MyString& rhs) noexcept;