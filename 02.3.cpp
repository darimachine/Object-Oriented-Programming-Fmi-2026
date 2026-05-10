#include "02.3.h"
#include <cstring>

void VehicleList::free() {
    for (size_t i = 0; i < cap; i++) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
}

void VehicleList::copyFrom(const VehicleList& other) {
    cap = other.cap;
    currentSize = other.currentSize;
    data = new Vehicle * [cap];
    for (size_t i = 0; i < cap; i++) {
        data[i] = other.data[i] ? new Vehicle(*other.data[i]) : nullptr;
    }
}

void VehicleList::resize() {
    size_t    newCap = cap * 2;
    Vehicle** newData = new Vehicle * [newCap];
    for (size_t i = 0; i < newCap; i++) {
        newData[i] = (i < cap) ? data[i] : nullptr;
    }
    delete[] data;
    data = newData;
    cap = newCap;
}

VehicleList::VehicleList(size_t initialCap)
    : cap(initialCap), currentSize(0)
{
    data = new Vehicle * [cap];
    for (size_t i = 0; i < cap; i++) data[i] = nullptr;
}

VehicleList::~VehicleList() { free(); }
VehicleList::VehicleList(const VehicleList& other) { copyFrom(other); }
VehicleList& VehicleList::operator=(const VehicleList& other) {
    if (this != &other) { free(); copyFrom(other); }
    return *this;
}

VehicleList& VehicleList::operator+=(const Vehicle& v) {
    if (find(v.getRegNum())) return *this;
    if (currentSize == cap)  resize();

    for (size_t i = 0; i < cap; i++) {
        if (data[i] == nullptr) {
            data[i] = new Vehicle(v);
            currentSize++;
            break;
        }
    }
    return *this;
}

VehicleList& VehicleList::operator-=(const Registration& reg) {
    return *this -= reg.toString();
}

VehicleList& VehicleList::operator-=(const char* regStr) {
    for (size_t i = 0; i < cap; i++) {
        if (data[i] && strcmp(data[i]->getRegNum(), regStr) == 0) {
            delete data[i];
            data[i] = nullptr;
            currentSize--;
            break;
        }
    }
    return *this;
}

Vehicle* VehicleList::find(const Registration& reg) const {
    return find(reg.toString());
}

Vehicle* VehicleList::find(const char* reg) const {
    for (size_t i = 0; i < cap; i++) {
        if (data[i] && strcmp(data[i]->getRegNum(), reg) == 0)
            return data[i];
    }
    return nullptr;
}

int VehicleList::operator()(const char* cityCode) const {
    int    count = 0;
    size_t codeLen = strlen(cityCode);
    for (size_t i = 0; i < cap; i++) {
        if (data[i]) {
            const char* reg = data[i]->getRegNum();
            if (strncmp(reg, cityCode, codeLen) == 0 &&
                reg[codeLen] >= '0' && reg[codeLen] <= '9') {
                count++;
            }
        }
    }
    return count;
}

VehicleList::operator bool() const { return currentSize > 0; }

bool   VehicleList::isEmpty()              const { return currentSize == 0; }
size_t VehicleList::size()                 const { return currentSize; }
size_t VehicleList::capacity()             const { return cap; }
bool   VehicleList::isFreeSlot(size_t pos) const { return pos < cap && data[pos] == nullptr; }

Vehicle* VehicleList::operator[](size_t index) {
    if (index >= cap) return nullptr;
    return data[index];
}
const Vehicle* VehicleList::operator[](size_t index) const {
    if (index >= cap) return nullptr;
    return data[index];
}

std::strong_ordering VehicleList::operator<=>(const VehicleList& other) const {
    if (currentSize != other.currentSize)
        return currentSize <=> other.currentSize;

    const char* reg1 = nullptr;
    const char* reg2 = nullptr;
    for (size_t i = 0; i < cap && !reg1; i++)
        if (data[i]) reg1 = data[i]->getRegNum();
    for (size_t i = 0; i < other.cap && !reg2; i++)
        if (other.data[i]) reg2 = other.data[i]->getRegNum();

    if (!reg1 && !reg2) return std::strong_ordering::equal;
    if (!reg1)          return std::strong_ordering::less;
    if (!reg2)          return std::strong_ordering::greater;

    int cmp = strcmp(reg1, reg2);
    if (cmp < 0) return std::strong_ordering::less;
    if (cmp > 0) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

bool VehicleList::operator==(const VehicleList& other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list) {
    for (size_t i = 0; i < list.cap; i++) {
        if (list.data[i]) os << "[" << i << "]: " << *list.data[i] << "\n";
        else              os << "[" << i << "]: *\n";
    }
    return os;
}