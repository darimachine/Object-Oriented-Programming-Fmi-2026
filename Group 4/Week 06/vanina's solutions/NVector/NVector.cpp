#include "NVector.h"

#include <iostream>

void NVector::copyFrom(const NVector &other) {
    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void NVector::free() {
    delete[] data;

    data = nullptr;
    size = 0;
}

int NVector::getSize() const {
    return size;
}

void NVector::resize(const int newSize) {
    int *newData = new int[newSize]{0};

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}


//
NVector::NVector() {
    this->size = 3;
    this->data = new int[this->size];
    data[0] = 0;
    data[1] = 0;
    data[2] = 0;
}

NVector::NVector(const int size) {
    this->size = size;
    this->data = new int[this->size];
}

NVector::NVector(const int *data, const int size) {
    this->size = size;
    this->data = new int[this->size]{0};
    for (int i = 0; i < this->size; i++) {
        this->data[i] = data[i];
    }
}

NVector::NVector(const NVector &other) {
    copyFrom(other);
}

NVector &NVector::operator=(const NVector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

NVector::~NVector() {
    free();
}


//
NVector &NVector::operator+=(const NVector &other) {
    for (int i = 0; i < size; i++) {
        this->data[i] += other.data[i];
    }
    return *this;
}

NVector &NVector::operator-=(const NVector &other) {
    for (int i = 0; i < size; i++) {
        this->data[i] -= other.data[i];
    }
    return *this;
}

NVector &NVector::operator*=(const int scalar) {
    for (int i = 0; i < size; i++) {
        this->data[i] *= scalar;
    }
    return *this;
}


//
const int &NVector::operator[](const int index) const {
    return data[index];
}

int &NVector::operator[](const int index) {
    return data[index];
}

NVector::operator bool() const {
    for (int i = 0; i < size; i++) {
        if (data[i] != 0) {
            return true;
        }
    }
    return false;
}

NVector NVector::operator()(std::function<int(int)> funct) const {
    NVector result(*this);

    for (int i = 0; i < size; i++) {
        result[i] = funct(data[i]);
    }
    return result;
}


//
NVector operator+(const NVector &lhs, const NVector &rhs) {
    const int maxSize = std::max(lhs.size, rhs.size);
    const int minSize = std::min(lhs.size, rhs.size);
    int *newData = new int[maxSize]{0};

    for (int i = 0; i < minSize; i++) {
        newData[i] = lhs.data[i] + rhs.data[i];
    }

    if (maxSize == minSize) {
        return NVector(newData, maxSize);
    }

    if (maxSize == lhs.size) {
        for (int i = minSize; i < maxSize; i++) {
            newData[i] = lhs.data[i];
        }
    } else {
        for (int i = minSize; i < maxSize; i++) {
            newData[i] = rhs.data[i];
        }
    }

    return NVector(newData, maxSize);
}

NVector operator-(NVector &lhs, NVector &rhs) {
    const int maxSize = std::max(lhs.size, rhs.size);
    const int minSize = std::min(lhs.size, rhs.size);
    int *newData = new int[maxSize]{0};

    if (minSize == lhs.getSize()) {
        lhs.resize(maxSize);
    }
    if (minSize == rhs.getSize()) {
        rhs.resize(minSize);
    }

    for (int i = 0; i < maxSize; i++) {
        newData[i] = lhs.data[i] - rhs.data[i];
    }
    return NVector(newData, maxSize);
}

NVector operator*(const NVector &vector, int scalar) {
    NVector result(vector.getSize());
    result *= scalar;
    return result;
}

NVector operator*(int scalar, const NVector &vector) {
    return vector * scalar;
}

int operator%(NVector &lhs, NVector &rhs) {
    const int maxSize = std::max(lhs.getSize(), rhs.getSize());
    const int minSize = std::min(lhs.getSize(), rhs.getSize());

    if (minSize == lhs.getSize()) {
        lhs.resize(maxSize);
    }
    if (minSize == rhs.getSize()) {
        rhs.resize(maxSize);
    }

    int result = 0;
    for (int i = 0; i < maxSize; i++) {
        result += lhs[i] * rhs[i];
    }
    return result;
}

bool operator|(NVector &lhs, NVector &rhs) {
    return (lhs % rhs == 0) ? true : false;
}

bool operator||(const NVector &lhs, const NVector &rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        return false;
    }

    const int size = lhs.getSize();
    const double scalar = (double) lhs[0] / lhs[1];
    for (int i = 1; i < size; i++) {
        if (std::abs((double) lhs[i] / rhs[i] - scalar) > EPSILON) {
            return false;
        }
    }
    return true;
}

double operator~(const NVector &vector) {
    const int size = vector.getSize();

    double result = 0;
    for (int i = 0; i < size; i++) {
        result += vector[i] * vector[i];
    }
    return std::sqrt(result);
}


//
std::ostream &operator<<(std::ostream &os, const NVector &v) {
    os << "(";

    const int size = v.getSize();
    for (int i = 0; i < size; i++) {
        os << v[i];
        if (i != size - 1)
            os << ", ";
    }

    os << ")";
    return os;
}

std::istream &operator>>(std::istream &is, NVector &v) {
    const int size = v.getSize();

    for (int i = 0; i < size; i++) {
        is >> v[i];
    }
    return is;
}


//
bool operator==(const NVector &lhs, const NVector &rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        return false;
    }

    return (~lhs - ~rhs) < EPSILON;
}

bool operator!=(const NVector &lhs, const NVector &rhs) {
    return !(lhs == rhs);
}

bool operator<(const NVector &lhs, const NVector &rhs) {
    const int minSize = std::min(lhs.getSize(), rhs.getSize());

    for (int i = 0; i < minSize; i++) {
        if (lhs[i] < rhs[i]) {
            return true;
        }
        if (lhs[i] > rhs[i]) {
            return false;
        }
    }
    return lhs.getSize() < rhs.getSize();
}

bool operator<=(const NVector &lhs, const NVector &rhs) {
    return !(rhs < lhs);
}

bool operator>(const NVector &lhs, const NVector &rhs) {
    return rhs < lhs;
}

bool operator>=(const NVector &lhs, const NVector &rhs) {
    return !(lhs < rhs);
}


//
std::strong_ordering operator<=>(const NVector &lhs, const NVector &rhs) {
    const int minSize = std::min(lhs.getSize(), rhs.getSize());

    for (int i = 0; i < minSize; i++) {
        auto cmp = lhs[i] <=> rhs[i];
        if (cmp < 0) {
            continue;
        }
        return cmp;
    }
    return lhs.getSize() <=> rhs.getSize();
}
