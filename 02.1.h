#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <compare>
#include <cstring>

class Registration {
private:
    char value[9];
    bool isValid(const char* str) const;

public:
    Registration(const char* str);
    const char* toString() const;
    friend std::ostream& operator<<(std::ostream& os, const Registration& r);
    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;
    std::strong_ordering operator<=>(const Registration& other) const;
};