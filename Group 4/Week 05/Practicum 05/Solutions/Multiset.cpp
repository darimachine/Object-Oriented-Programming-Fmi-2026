#include "MultiSet.h"
#include <print>
using namespace std;

int MultiSet::bytesNeeded(int n) {
    return (n + 3) / 4;
}

int MultiSet::getCount(int i) const {
    int byteIdx = i / 4;
    int bitIdx  = (i % 4) * 2;
    return (data[byteIdx] >> bitIdx) & 3;
}

void MultiSet::setCount(int i, int count) {
    int byteIdx = i / 4;
    int bitIdx  = (i % 4) * 2;
    uint8_t mask = ~(3 << bitIdx);
    data[byteIdx] = (data[byteIdx] & mask) | ((count & 3) << bitIdx);
}

MultiSet::MultiSet(int n) : n(n) {
    data = new uint8_t[bytesNeeded(n)]();
}

MultiSet::~MultiSet() {
    delete[] data;
}

MultiSet::MultiSet(const MultiSet& other) : n(other.n) {
    int bytes = bytesNeeded(n);
    data = new uint8_t[bytes];
    for (int i = 0; i < bytes; i++)
        data[i] = other.data[i];
}

MultiSet& MultiSet::operator=(const MultiSet& other) {
    if (this == &other) return *this;
    delete[] data;
    n = other.n;
    int bytes = bytesNeeded(n);
    data = new uint8_t[bytes];
    for (int i = 0; i < bytes; i++)
        data[i] = other.data[i];
    return *this;
}

void MultiSet::add(int x) {
    if (x < 0 || x >= n) return;
    int c = getCount(x);
    if (c < 3) setCount(x, c + 1);
}

void MultiSet::remove(int x) {
    if (x < 0 || x >= n) return;
    int c = getCount(x);
    if (c > 0) setCount(x, c - 1);
}

int MultiSet::count(int x) const {
    if (x < 0 || x >= n) return 0;
    return getCount(x);
}

void MultiSet::print() const {
    bool first = true;
    for (int i = 0; i < n; i++) {
        int c = getCount(i);
        for (int j = 0; j < c; j++) {
            if (!first) print("\' \'");
            print("{}", i)
            first = false;
        }
    }
    println();
}

MultiSet MultiSet::intersect(const MultiSet& a, const MultiSet& b) {
    int smaller = a.n < b.n ? a.n : b.n;
    MultiSet result(smaller);
    for (int i = 0; i < smaller; i++) {
        int ca = a.getCount(i), cb = b.getCount(i);
        result.setCount(i, ca < cb ? ca : cb);
    }
    return result;
}

MultiSet MultiSet::unite(const MultiSet& a, const MultiSet& b) {
    int larger = a.n > b.n ? a.n : b.n;
    MultiSet result(larger);
    for (int i = 0; i < larger; i++) {
        int ca = (i < a.n) ? a.getCount(i) : 0;
        int cb = (i < b.n) ? b.getCount(i) : 0;
        result.setCount(i, ca > cb ? ca : cb);
    }
    return result;
}