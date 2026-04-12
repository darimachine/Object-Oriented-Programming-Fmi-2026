#pragma once
#include <cstdint>

class MultiSet {
    int n;
    uint8_t* data;

    static int bytesNeeded(int n);
    int getCount(int i) const;
    void setCount(int i, int count);

public:
    MultiSet(int n);
    ~MultiSet();
    MultiSet(const MultiSet& other);
    MultiSet& operator=(const MultiSet& other);

    void add(int x);
    void remove(int x);
    int count(int x) const;
    void print() const;

    MultiSet intersect(const MultiSet& a, const MultiSet& b);
    MultiSet unite(const MultiSet& a, const MultiSet& b);
};