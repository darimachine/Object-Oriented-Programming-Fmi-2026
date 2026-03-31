#include "MyString.h"

#include <cstring>

void MyString::copyFrom(const MyString &other) {
    capacity = other.getSize() + 1;
    string = new char[capacity];
    strcpy(string, other.string);
}

void MyString::free() {
    delete[] string;

    string = nullptr;
    capacity = 0;
}

//
int MyString::getSize() const {
    return strlen(string);
}

int MyString::getCapacity() const {
    return capacity;
}

void MyString::resize(int newCapacity) {
    if (newCapacity < capacity) {
        std::cout << "new capacity is less than the original" << std::endl;
        return;
    }

    char *newString = new char[newCapacity];
    strcpy(newString, string);

    delete[] string;
    string = nullptr;
    string = newString;
    capacity = 0;
}


//
MyString::MyString() {
    string = nullptr;
    capacity = 0;
}

MyString::MyString(const char *data) {
    capacity = strlen(data) + 1;
    string = new char[capacity];
    strcpy(string, data);
}

MyString::MyString(const MyString &other) {
    copyFrom(other);
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MyString::~MyString() {
    free();
}

const char &MyString::operator[](const int index) const {
    return string[index];
}

char &MyString::operator[](const int index) {
    return string[index];
}


//
MyString MyString::substr(int startIndex, int len) const {
    if (startIndex + len > getSize()) {
        std::cout << "invald data" << std::endl;
        return MyString();
    }

    char *result = new char[len + 1];
    const int size = getSize();

    for (int i = startIndex, j = 0; i < size && j < len; i++, j++) {
        result[j] = string[i];
    }
    result[len + 1] = '\0';

    return MyString(result);
}

const char *MyString::c_str() const {
    return string;
}

MyString &MyString::operator+=(const MyString &other) {
    const int oldSize = getSize();
    const int newSize = getSize() + other.getSize();
    char *result = new char[newSize + 1];
    strcpy(result, string);

    // for (int i=oldSize; i<newSize; i++) {
    //     result[i] = other[i - oldSize];
    // }
    // result[newSize] = '\0';
    strcat(result, other.string);

    delete[] string;
    string = result;
    capacity = newSize + 1;

    return *this;
}


//
MyString operator+(const MyString &lhs, const MyString &rhs) {
    const int leftSize = lhs.getSize();
    const int newSize = lhs.getSize() + rhs.getSize();
    char *result = new char[newSize + 1];

    for (int i = 0; i < leftSize; i++) {
        result[i] = lhs[i];
    }
    for (int i = leftSize; i < newSize; i++) {
        result[i] = rhs[i - leftSize];
    }
    result[newSize] = '\0';

    return MyString(result);
}


//
std::ostream &operator<<(std::ostream &os, const MyString &str) {
    os << "\"";
    os << str.string << "\"";

    return os;
}

std::istream &operator>>(std::istream &is, MyString &str) {
    int size;
    std::cout << "size = ";
    is >> size;

    for (int i = 0; i < size; i++) {
        is >> str[i];
    }
    return is;
}


//
bool operator==(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString &lhs, const MyString &rhs) {
    return !(lhs == rhs);
}

bool operator<(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString &lhs, const MyString &rhs) {
    return rhs < lhs;
}

bool operator<=(const MyString &lhs, const MyString &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const MyString &lhs, const MyString &rhs) {
    return !(rhs > lhs);
}


//
std::strong_ordering operator<=>(const MyString &lhs, const MyString &rhs) {
    return strcmp(lhs.c_str(), rhs.c_str()) <=> 0;
}
