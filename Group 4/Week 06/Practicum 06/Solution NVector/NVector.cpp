//
// Created by Boris Bozhilov on 4/2/2026.
//

#include "NVector.h"

#include <iostream>

constexpr double EPSILON = 0.0001;

// rule of 3
NVector::NVector() : data(new int[3]{0}), size(3) {
}

NVector::NVector(const int size) : data(new int[size]{0}), size(size){
}

NVector::NVector(const int *data, const int size) : data(new int[size]{0}), size(size) {

    for (int i = 0; i < size; i++) {
        this->data[i] = data[i];
    }
}

NVector::NVector(const NVector &other) : data(new int[other.size]), size(other.size) {

    copyDataFrom(other);
}

NVector& NVector::operator=(const NVector &other) {

    if (this == &other) return *this;

    delete[] this->data;

    this->data = new int[other.size];

    this->size = other.size;

    copyDataFrom(other);

    return *this;
}

NVector::~NVector() {

    delete[] data;
    data = nullptr;
    size = 0;
}

// utility functions
void NVector::copyDataFrom(const NVector &other) {

    for (int i = 0 ; i < other.size; i++) {

        this->data[i] = other.data[i];
    }
}

void NVector::changeData(const std::function<int(int, int)> &function, const NVector &other) {

    int minSize = std::min(size, other.size);

    for (int i = 0; i < minSize; i++) {

    data[i] = function(data[i], other[i]);
    }
}

void NVector::upsizeVector(const int upSize) {

    if (upSize <= size) return;

    int* upsizedData = new int[upSize]{0};

    for (int i = 0; i < size; i++) {
        upsizedData[i] = data[i];
    }

    size = upSize;

    delete[] data;
    data = upsizedData;
    upsizedData = nullptr;
}

void NVector::downsizeVector(const int downSize) {

    if (downSize >= size) return;

    int* downsizedData = new int[downSize]{0};

    for (int i = 0; i < downSize; i++) {
        downsizedData[i] = data[i];
    }

    size = downSize;

    delete[] data;
    data = downsizedData;
    downsizedData = nullptr;
}

int NVector::getTrimVectorSize() const {

    int countExcessValues = 0;

    for (int i = size - 1; i > 0; i++) {
        if (data[i] != 0) break;
        countExcessValues++;
    }

    return size - countExcessValues;
}

void NVector::setToTheLargerSize(NVector &vector1, NVector &vector2) {

    if (vector1.size == vector2.size) return;
    bool vector1IsLarger = vector1.size > vector2.size;

    if (vector1IsLarger) vector2.upsizeVector(vector1.size);
    else vector1.upsizeVector(vector2.size);
}


// getters and setters
int NVector::getSize() const {
    return size;
}

const int *NVector::getData() const {
    return data;
}

void NVector::setSize(const int size) {
    this->size = size;
}

// arithmetic operators
NVector& NVector::operator+=(const NVector &other) {

    if (this->size < other.size) this->upsizeVector(other.size);

    changeData([](const int value1, const int value2){return value1 + value2;}, other);

    return *this;
}

NVector &NVector::operator-=(const NVector &other) {

    if (this->size < other.size) this->upsizeVector(other.size);

    changeData([](const int value1, const int value2){return value1 - value2;}, other);

    return *this;
}

NVector &NVector::operator*=(const int value) {

    *this = (*this)([value](const int value1){return value1 * value;});

    return *this;
}

NVector operator+(NVector lhsVector, const NVector &rhsVector) {

    lhsVector += rhsVector;
    return lhsVector;
}

NVector operator-(NVector lhsVector, const NVector &rhsVector) {

    lhsVector -= rhsVector;
    return  lhsVector;
}

NVector NVector::operator*(const int value) const {

    return (*this)([value](const int sourceData){return sourceData * value;});
}

NVector operator*(const int value, NVector lhsVector) {

    lhsVector *= value;
    return  lhsVector;
}

int operator%(const NVector &lhsVector, const NVector &rhsVector) {

    int minSize = std::min(lhsVector.size, rhsVector.size);

    int result = 0;

    for (int i = 0; i < minSize; i++) {
        result += lhsVector[i] * rhsVector[i];
    }

    return result;
}

// specific operators
// note
// if the index is out of bounds, it's set to the closest bound - might be dangerous
int& NVector::operator[](int index) {

    if (index >= size) return data[size - 1];
    if (index < 0) return data[0];

    return data[index];
}

int NVector::operator[](int index) const {

    if (index >= size) return data[size - 1];
    if (index < 0) return data[0];

    return data[index];
}

int NVector::operator~() const {
    return size;
}

NVector::operator bool() const {

    for (int i = 0; i < size; i++) {
        if (data[i] != 0) return true;
    }

    return false;
}

bool NVector::operator|(const NVector &other) const {

    return (*this % other == 0);
}

// note
// in order for 2 vectors to be parallel they must have the same size
bool NVector::operator||(const NVector &other) const {

    if (!((*this) && other)) return false;
    if (~(*this) != ~other) return false;

    const double coefficient = (double)(*this)[0] / other[0];

    for (int i = 1; i < size; i++) {

        double currCoefficient = (double)(*this)[i] / other[i];

        if (std::abs(coefficient - currCoefficient) > EPSILON) return false;
    }

    return true;
}

NVector NVector::operator()(const std::function<int(int)> &function) const {

    NVector result = NVector(size);

    for (int i = 0; i < size; i++) {

        result[i] = function(data[i]);
    }

    return result;
}

// io operators
std::ostream& operator<<(std::ostream &outStream, const NVector &vector) {

    outStream << '(';

    for (int i = 0 ; i < vector.size - 1; i++) {
        outStream << vector.data[i] << ", ";
    }

    outStream << vector.data[vector.size - 1] << ')';

    return outStream;
}

std::istream& operator>>(std::istream &inStream, NVector &vector) {

    for (int i = 0; i < vector.size; i++) {

            inStream >> vector.data[i];
    }

    return inStream;
}