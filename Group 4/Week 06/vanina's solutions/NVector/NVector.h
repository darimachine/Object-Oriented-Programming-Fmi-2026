#ifndef NVECTOR_NVECTOR_H
#define NVECTOR_NVECTOR_H

#include <functional>
#include<iostream>

constexpr double EPSILON = 0.000001;

class NVector {
    int *data;
    int size;

    //
    void copyFrom(const NVector &other);

    void free();

    //
    friend NVector operator+(const NVector &lhs, const NVector &rhs);

    friend NVector operator-(NVector &lhs, NVector &rhs);

public:
    int getSize() const;

    //
    void resize(int newSize);

    //
    NVector();

    explicit NVector(int size);

    NVector(const int *data, int size);

    NVector(const NVector &other);

    NVector &operator=(const NVector &other);

    ~NVector();

    //
    NVector &operator+=(const NVector &other);

    NVector &operator-=(const NVector &other);

    NVector &operator*=(int scalar);

    //
    const int &operator[](int index) const;

    int &operator[](int index);

    //
    operator bool() const;

    NVector operator()(std::function<int(int)> funct) const;
};

NVector operator+(const NVector &lhs, const NVector &rhs);

NVector operator-(NVector &lhs, NVector &rhs);

//
NVector operator*(const NVector &vector, int scalar);

NVector operator*(int scalar, const NVector &vector);

int operator%(NVector &lhs, NVector &rhs);

//
bool operator|(NVector &lhs, NVector &rhs);

bool operator||(const NVector &lhs, const NVector &rhs);

//
double operator~(const NVector &vector);

//
std::ostream &operator<<(std::ostream &os, const NVector &v);

std::istream &operator>>(std::istream &is, NVector &v);

//
bool operator==(const NVector &lhs, const NVector &rhs);

bool operator!=(const NVector &lhs, const NVector &rhs);

bool operator<(const NVector &lhs, const NVector &rhs);

bool operator<=(const NVector &lhs, const NVector &rhs);

bool operator>(const NVector &lhs, const NVector &rhs);

bool operator>=(const NVector &lhs, const NVector &rhs);

//
std::strong_ordering operator<=>(const NVector &lhs, const NVector &rhs);

#endif //NVECTOR_NVECTOR_H
