//
// Created by Boris Bozhilov on 4/2/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NVECTOR_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NVECTOR_H
#include <functional>
#include <iosfwd>
#include <compare>

class NVector {

    static constexpr int DEFAULT_VECTOR_SIZE = 3;

private:

    int* data;
    int size;

    // util functions
    void copyDataFrom(const NVector &other);
    void changeData(const std::function<int(int, int)> &function, const NVector &other);
    void upsizeVector(const int upSize);
    void downsizeVector(const int downSize);
    int getTrimVectorSize() const;
    static void setToTheLargerSize(NVector &vector1, NVector &vector2);

public:

    // rule of 3
    NVector();
    explicit NVector(const int size);
    NVector(const int* data, const int size);

    NVector(const NVector &other);
    NVector& operator=(const NVector &other);

    ~NVector();

    // getters and setters
    const int* getData() const;
    int getSize() const;

    // the setter for data is useless for now
    // void setData(const int* data);
    void setSize(const int size);

    // arithmetic operators
    NVector& operator+=(const NVector &other);
    NVector& operator-=(const NVector &other);
    NVector& operator*=(const int value);

    friend NVector operator+(NVector lhsVector, const NVector& rhsVector);
    friend NVector operator-(NVector lhsVector, const NVector& rhsVector);
    NVector operator*(const int value) const;
    friend NVector operator*(const int value, NVector lhsVector);
    friend int operator%(const NVector &lhsVector, const NVector& rhsVector);

    // specific operators
    int& operator[](int index);
    int operator[](int index) const;
    int operator~() const;
    explicit operator bool() const;
    bool operator|(const NVector &other) const;
    bool operator||(const NVector &other) const;
    NVector operator()(const std::function<int(int)> &function) const;

    // comparison operators
    friend bool operator==(const NVector &lhsVector, const NVector &rhsVector) {

        // check if it's the same objects
        if (&lhsVector == &rhsVector) return true;

        int lhsSize = ~lhsVector;

        if (lhsVector.getTrimVectorSize() != rhsVector.getTrimVectorSize()) return false;

        for (int i = 0; i < lhsSize; i++) {

            if (lhsVector[i] != rhsVector[i]) return false;
        }

        return true;
    };


    // note
    // this is the way the comparison operators are implemented without using the <=> operator

    // friend bool operator>(const NVector &lhsVector, const NVector &rhsVector) {
    //     if (lhsVector == rhsVector) return false;
    //
    //     int minSize = std::min(lhsVector.size, rhsVector.size);
    //
    //     for (int i = 0; i < minSize; i++) {
    //
    //         if (lhsVector.data[i] == rhsVector.data[i]) continue;
    //
    //         if (lhsVector.data[i] > rhsVector.data[i]) return true;
    //         return false;
    //     }
    //
    //     if (lhsVector.size > rhsVector.size) return true;
    //     return false;
    // }
    // friend bool operator<(const NVector &lhsVector, const NVector &rhsVector) {
    //     if (rhsVector > lhsVector) return true;
    //     return false;
    // }
    // friend bool operator>=(const NVector &lhsVector, const NVector &rhsVector) {
    //     if (rhsVector > lhsVector) return false;
    //     return true;
    // }
    // friend bool operator<=(const NVector &lhsVector, const NVector &rhsVector) {
    //     if (lhsVector > rhsVector) return false;
    //     return true;
    // }
    // friend bool operator!=(const NVector &lhsVector, const NVector &rhsVector) {
    //     if (lhsVector == rhsVector) return false;
    //     return true;
    // }

    // spaceship operator
    friend auto operator<=>(const NVector& lhsVector, const NVector& rhsVector) {

        if (&lhsVector == &rhsVector) return std::strong_ordering::equal;

        int minSize = std::min(lhsVector.size, rhsVector.size);

        for (int i = 0; i < minSize; i++) {

            auto comparator = lhsVector.data[i] <=> rhsVector.data[i];

            if (comparator != 0) return comparator;
        }

        return lhsVector.size <=> rhsVector.size;;
    }

    // io operators
    friend std::ostream& operator<<(std::ostream &outStream, const NVector &vector);
    friend std::istream& operator>>(std::istream &inStream, NVector &vector);

};


#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NVECTOR_H