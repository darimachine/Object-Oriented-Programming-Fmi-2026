#pragma once
#include<print>

class MultiSet {
private:
    static const int BITS_PER_ELEMENT = 3;
    static const int ELEMENT_MAX_VALUE = 3;
    static const int BYTE_SIZE = 8;

    size_t n = 0;
    size_t  byteCount = 0;
    unsigned char* data = nullptr;

    int getValue(unsigned x) const;
    void setValue(unsigned x, unsigned value);

	void copyFrom(const MultiSet& other);
    void free();

public:
    MultiSet(int n);

    MultiSet(const MultiSet& other);

    MultiSet& operator=(const MultiSet& other);

    ~MultiSet();

    void add(unsigned x);

    void remove(unsigned x);

    int count(unsigned x) const;

    void printAll() const;

    static MultiSet getIntersection(const MultiSet& a, const MultiSet& b);

    static MultiSet getUnion(const MultiSet& a, const MultiSet& b);
};
