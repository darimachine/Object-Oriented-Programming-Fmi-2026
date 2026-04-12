#include "NumberWrapper.h"

NumberWrapper::NumberWrapper(int val) : value(val) {}

NumberWrapper& NumberWrapper::operator+=(const NumberWrapper& other) {
    value += other.value;
    return *this;
}

NumberWrapper& NumberWrapper::operator-=(const NumberWrapper& other) {
    value -= other.value;
    return *this;
}

NumberWrapper& NumberWrapper::operator*=(const NumberWrapper& other) {
    value *= other.value;
    return *this;
}

NumberWrapper& NumberWrapper::operator/=(const NumberWrapper& other) {
    if (other.value == 0) {
        // throw exception
        // for now we will just ignore it
        return *this;
    }
    value /= other.value;
    return *this;
}

NumberWrapper NumberWrapper::operator++(int dummy) {
    std::cout << "suffix operator++" << std::endl;
    NumberWrapper result(*this);
    ++value;
    return result;
}

NumberWrapper& NumberWrapper::operator++() {
    std::cout << "prefix operator++" << std::endl;
    ++value;
    return *this;
}

NumberWrapper NumberWrapper::operator--(int dummy) {
    std::cout << "suffix operator++" << std::endl;
    NumberWrapper result(*this);
    --value;
    return result;
}

NumberWrapper& NumberWrapper::operator--() {
    std::cout << "prefix operator++" << std::endl;
    --value;
    return *this;
}

NumberWrapper::operator bool() const {
    return value != 0;
}

NumberWrapper::operator int() const {
    return value;
}

std::ostream& operator<<(std::ostream& os, const NumberWrapper& number) {
    return os << (int) number; // this will call operator int
}

std::istream& operator>>(std::istream& is, NumberWrapper& number) {
    return is >> number.value; // we have access to the value property, because operator>> is a friend function
}

NumberWrapper operator+(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    NumberWrapper result(lhs);
    result += rhs;
    return result;
}

NumberWrapper operator-(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    NumberWrapper result(lhs);
    result -= rhs;
    return result;
}

NumberWrapper operator*(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    NumberWrapper result(lhs);
    result *= rhs;
    return result;
}

NumberWrapper operator/(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    NumberWrapper result(lhs);
    result /= rhs;
    return result;
}

bool operator==(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return (int) lhs == (int) rhs;
}

bool operator!=(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return !(lhs == rhs); // here we just reuse the already implemented operator==
}

bool operator<(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return (int) lhs < (int) rhs;
}

bool operator>(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return rhs >= lhs && lhs != rhs;
}

bool operator<=(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return !(lhs > rhs);
}

bool operator>=(const NumberWrapper& lhs, const NumberWrapper& rhs) {
    return !(lhs < rhs);
}
