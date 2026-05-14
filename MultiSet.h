#pragma once
#include <cstdint>
class MultiSet
{
private:
    uint16_t* data;
    size_t n;
    size_t blocksCount;

    size_t getBitIndex(size_t) const;
    uint8_t getCount(size_t) const;
    void setCount(size_t, uint8_t);

    void copyFrom(const MultiSet&);
    void free();

public:
    MultiSet(size_t);
    MultiSet(const MultiSet&);
    MultiSet& operator=(const MultiSet&);
    ~MultiSet();

    void add(size_t);
    void remove(size_t);
    uint8_t count(size_t) const;
    void print() const;
    static MultiSet intersection(const MultiSet&, const MultiSet&);
    static MultiSet unionSet(const MultiSet&, const MultiSet&);
};

