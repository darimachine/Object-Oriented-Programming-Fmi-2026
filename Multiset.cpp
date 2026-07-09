#include "MultiSet.h"

MultiSet::MultiSet(int n) : n(n) 
{
    byteCount = (n * BITS_PER_ELEMENT + BYTE_SIZE - 1) / BYTE_SIZE;
    data = new unsigned char[byteCount];

    for (size_t i = 0; i < byteCount; i++)
    {
        data[i] = 0;
    }
}

MultiSet::MultiSet(const MultiSet& other)
{
	copyFrom(other);
}

void MultiSet::copyFrom(const MultiSet& other) 
{
    n = other.n;
    byteCount = other.byteCount;
    data = new unsigned char[byteCount];

    for (size_t i = 0; i < byteCount; i++) 
    {
        data[i] = other.data[i];
    }
}

void MultiSet::free() 
{
    delete[] data;
    data = nullptr;
}

MultiSet& MultiSet::operator=(const MultiSet& other) 
{
    if (this == &other)
    {
        return *this;
    }

    free();
    copyFrom(other);

    return *this;
}

MultiSet::~MultiSet() 
{
    delete[] data;
    data = nullptr;
}

int MultiSet::getValue(unsigned x) const 
{
    int startBit = x * BITS_PER_ELEMENT;
    int byteIndex = startBit / BYTE_SIZE;
    int bitOffset = startBit % BYTE_SIZE;

    unsigned int value = data[byteIndex] >> bitOffset;

    int bitsInFirstByte = BYTE_SIZE - bitOffset;

    if (bitsInFirstByte < BITS_PER_ELEMENT) 
    {
        int remainingBits = BITS_PER_ELEMENT - bitsInFirstByte;
        unsigned int next = data[byteIndex + 1] & ((1 << remainingBits) - 1);
        value |= next << bitsInFirstByte;
    }

    int mask = (1 << BITS_PER_ELEMENT) - 1;

    return value & mask;
}

void MultiSet::setValue(unsigned x, unsigned value) 
{
    int startBit = x * BITS_PER_ELEMENT;
    int byteIndex = startBit / BYTE_SIZE;
    int bitOffset = startBit % BYTE_SIZE;

    int mask = ((1 << BITS_PER_ELEMENT) - 1) << bitOffset;

    data[byteIndex] &= ~mask;
    data[byteIndex] |= (value << bitOffset);

    int bitsInFirstByte = BYTE_SIZE - bitOffset;

    if (bitsInFirstByte < BITS_PER_ELEMENT) 
    {
        int remainingBits = BITS_PER_ELEMENT - bitsInFirstByte;
        int next = (1 << remainingBits) - 1;

        data[byteIndex + 1] &= ~next;
        data[byteIndex + 1] |= (value >> bitsInFirstByte);
    }
}

void MultiSet::add(unsigned x) 
{
    unsigned num = getValue(x);

    if (num < ELEMENT_MAX_VALUE)
    {
        setValue(x, num + 1);
    }
}

void MultiSet::remove(unsigned x) 
{
    unsigned num = getValue(x);
    if (num > 0)
    {
        setValue(x, num - 1);
    }
}

int MultiSet::count(unsigned x) const 
{
    return getValue(x);
}

void MultiSet::printAll() const 
{
    for (size_t i = 0; i < n; i++) 
    {
        unsigned c = getValue(i);
        for (size_t j = 0; j < c; j++)
        {
            std::print("{} ",i);
        }
    }
    std::println();
}

MultiSet MultiSet::getIntersection(const MultiSet& a, const MultiSet& b) 
{
    size_t size = std::min(a.n,b.n);
    MultiSet result(size);

    for (size_t i = 0; i < size; i++) 
    {
        unsigned v = a.getValue(i);
        unsigned w = b.getValue(i);

        result.setValue(i, std::min(v,w));
    }
    return result;
}

MultiSet MultiSet::getUnion(const MultiSet& a, const MultiSet& b) 
{
    int size = std::max(a.n,b.n);
    MultiSet result(size);

    for (size_t i = 0; i < size; i++) 
    {
        unsigned v = (i < a.n ? a.getValue(i) : 0);
        unsigned w = (i < b.n ? b.getValue(i) : 0);

        result.setValue(i, std::max(v,w));
    }
    return result;
}