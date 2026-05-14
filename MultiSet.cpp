#include "MultiSet.h"
#include <print>

size_t MultiSet::getBitIndex(size_t num) const
{
    return num * 2;
}

uint8_t MultiSet::getCount(size_t num) const
{
    size_t bitIndex = getBitIndex(num);
    size_t blockIndex = bitIndex / 16;
    size_t offset = bitIndex % 16;

    return (data[blockIndex] >> offset) & 0b11;
}

void MultiSet::setCount(size_t num, uint8_t count)
{
    size_t bitIndex = getBitIndex(num);
    size_t blockIndex = bitIndex / 16;
    size_t offset = bitIndex % 16;

    data[blockIndex] &= ~(0b11 << offset);
    data[blockIndex] |= (count << offset);
}

void MultiSet::copyFrom(const MultiSet& other)
{
    n = other.n;
    blocksCount = other.blocksCount;

    data = new uint16_t[blocksCount];
    for (size_t i = 0; i < blocksCount; i++)
        data[i] = other.data[i];
}

void MultiSet::free()
{
    delete[] data;
    data = nullptr;
}

MultiSet::MultiSet(size_t n):n(n)
{
    blocksCount = (2 * n + 15) / 16;
    data = new uint16_t[blocksCount]{ 0 };
}

MultiSet::MultiSet(const MultiSet&other)
{
    copyFrom(other);
}

MultiSet& MultiSet::operator=(const MultiSet&other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

MultiSet::~MultiSet()
{
    free();
}

void MultiSet::add(size_t num)
{
    if (num >= n) {
        std::println("Invalid number!");
        return;
    }

    uint8_t c = getCount(num);
    if (c < 3) {
        setCount(num, c + 1);
    }
        
}

void MultiSet::remove(size_t num)
{
    if (num >= n) {
        std::println("Invalid number!");
        return;
    }

    uint8_t c = getCount(num);
    if (c > 0) {
        setCount(num, c - 1);
    }
        
}

uint8_t MultiSet::count(size_t num) const
{
    if (num >= n) {
        std::println("Invalid number!");
        return 0;
    }

    return getCount(num);
}

void MultiSet::print() const
{
    for (size_t i = 0; i < n; i++) {
        uint8_t c = getCount(i);
        for (int j = 0; j < c; j++) {
            std::print("{} ", i);
        }
           
    }
    std::print("\n");
}

MultiSet MultiSet::intersection(const MultiSet& a, const MultiSet& b)
{
    if (a.n != b.n) {
        std::println("Different sizes");
        return MultiSet(0);
    }

    MultiSet result(a.n);

    for (size_t i = 0; i < a.n; i++) {
        uint8_t c = std::min(a.getCount(i), b.getCount(i));
        result.setCount(i, c);
    }

    return result;
}

MultiSet MultiSet::unionSet(const MultiSet& a, const MultiSet& b)
{
    if (a.n != b.n) {
        std::println("Different sizes");
        return MultiSet(0);
    }


    MultiSet result(a.n);

    for (size_t i = 0; i < a.n; i++) {
        uint8_t c = std::max(a.getCount(i), b.getCount(i));
        result.setCount(i, c);
    }

    return result;
}





