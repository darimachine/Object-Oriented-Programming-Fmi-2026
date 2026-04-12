#pragma once
#include <iostream>

class NumberWrapper {
public:
    NumberWrapper() = default;
    explicit NumberWrapper(int val);

    NumberWrapper& operator+=(const NumberWrapper& other);
    NumberWrapper& operator-=(const NumberWrapper& other);
    NumberWrapper& operator*=(const NumberWrapper& other);
    NumberWrapper& operator/=(const NumberWrapper& other);

    NumberWrapper operator++(int dummy); // dummy param for postfix operator++
    NumberWrapper& operator++(); // no dummy param for prefix operator++

    NumberWrapper operator--(int dummy);
    NumberWrapper& operator--();

    operator int() const; // this is same as getter for the value
    operator bool() const; // this operator helps us use the object in an if statement and treat it as a bool

    friend std::istream& operator>>(std::istream& is, NumberWrapper& number);

private:
    int value = 0;
};

NumberWrapper operator+(const NumberWrapper& lhs, const NumberWrapper& rhs);
NumberWrapper operator-(const NumberWrapper& lhs, const NumberWrapper& rhs);
NumberWrapper operator*(const NumberWrapper& lhs, const NumberWrapper& rhs);
NumberWrapper operator/(const NumberWrapper& lhs, const NumberWrapper& rhs);
std::ostream& operator<<(std::ostream& os, const NumberWrapper& number);
bool operator==(const NumberWrapper& lhs, const NumberWrapper& rhs);
bool operator!=(const NumberWrapper& lhs, const NumberWrapper& rhs);
bool operator<(const NumberWrapper& lhs, const NumberWrapper& rhs);
bool operator>(const NumberWrapper& lhs, const NumberWrapper& rhs);
bool operator<=(const NumberWrapper& lhs, const NumberWrapper& rhs);
bool operator>=(const NumberWrapper& lhs, const NumberWrapper& rhs);
