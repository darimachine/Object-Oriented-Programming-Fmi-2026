#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

#include<iostream>


class MyString {
    char *string;
    int capacity;

    void copyFrom(const MyString &other);

    void free();

    friend std::ostream &operator<<(std::ostream &os, const MyString &str);

public:
    int getSize() const;

    int getCapacity() const;

    void resize(int newCapacity);

    //
    MyString();

    explicit MyString(const char *data);

    MyString(const MyString &other);

    MyString &operator=(const MyString &other);

    ~MyString();

    //
    const char &operator[](const int index) const;

    char &operator[](const int index);

    //
    MyString substr(int startIndex, int len) const;

    const char *c_str() const;

    //
    MyString &operator+=(const MyString &other);
};

//
MyString operator+(const MyString &lhs, const MyString &rhs);


//
std::ostream &operator<<(std::ostream &os, const MyString &str);

std::istream &operator>>(std::istream &is, MyString &str);


//
bool operator==(const MyString &lhs, const MyString &rhs);

bool operator!=(const MyString &lhs, const MyString &rhs);

bool operator<(const MyString &lhs, const MyString &rhs);

bool operator<=(const MyString &lhs, const MyString &rhs);

bool operator>(const MyString &lhs, const MyString &rhs);

bool operator>=(const MyString &lhs, const MyString &rhs);

//
std::strong_ordering operator<=>(const MyString &lhs, const MyString &rhs);

#endif //MYSTRING_MYSTRING_H
