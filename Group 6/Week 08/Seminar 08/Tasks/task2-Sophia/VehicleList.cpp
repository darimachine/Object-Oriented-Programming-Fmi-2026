#include "VehicleList.h"

void VehicleList::free() {
    for (unsigned i = 0; i < currentCapacity; ++i) {
        delete data[i];
    }
    delete[] data;
}

void VehicleList::copyFrom(const VehicleList& other) {
    count = other.count;
    currentCapacity = other.currentCapacity;
    data = new Vehicle*[currentCapacity];
    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (other.data[i]) data[i] = new Vehicle(*other.data[i]);
        else data[i] = nullptr;
    }
}

void VehicleList::resize() {
    unsigned oldCap = currentCapacity;
    currentCapacity *= 2;
    Vehicle** newData = new Vehicle*[currentCapacity];
    for (unsigned i = 0; i < oldCap; ++i) {
        newData[i] = data[i];
    }
    for (unsigned i = oldCap; i < currentCapacity; ++i) {
        newData[i] = nullptr;
    }
    delete[] data;
    data = newData;
}

VehicleList::VehicleList(unsigned cap) : count(0), currentCapacity(cap) {
    data = new Vehicle*[currentCapacity];
    for (unsigned i = 0; i < currentCapacity; ++i) {
        data[i] = nullptr;
    }
}

VehicleList::~VehicleList() { free(); }

VehicleList::VehicleList(const VehicleList& other) { 
    copyFrom(other); 
}

VehicleList& VehicleList::operator=(const VehicleList& other) {
    if (this != &other) { 
        free(); copyFrom(other); 
    }
    return *this;
}

unsigned VehicleList::size() const { 
    return count; 
}
unsigned VehicleList::capacity() const { 
    return currentCapacity; 
}
bool VehicleList::isEmpty() const { 
    return count == 0; 
}
bool VehicleList::isFreeSlot(unsigned pos) const {
    return pos < currentCapacity && data[pos] == nullptr;
}

VehicleList& VehicleList::operator+=(const Vehicle& v) {
    if (find(v.getRegistration())) {
        return *this;
    }

    if (count == currentCapacity) {
        resize();
    }
    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (!data[i]) {
            data[i] = new Vehicle(v);
            count++;
            break;
        }
    }
    return *this;
}

VehicleList& VehicleList::operator-=(const Registration& r) {
    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (data[i] && data[i]->getRegistration() == r) {
            delete data[i];
            data[i] = nullptr;
            count--;
            break;
        }
    }
    return *this;
}

unsigned VehicleList::operator()(const char* cityCode) const {
    unsigned result = 0;
    int codeLen = std::strlen(cityCode);
    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (data[i]) {
            if (std::strncmp(data[i]->getRegistration().toString(), cityCode, codeLen) == 0) {
                result++;
            }
        }
    }
    return result;
}

VehicleList::operator bool() const { 
    return count > 0; 
}

Vehicle* VehicleList::find(const Registration& r) {
    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (data[i] && data[i]->getRegistration() == r) {
            return data[i];
        }
    }
    return nullptr;
}

bool VehicleList::operator>(const VehicleList& other) const {
    if (count != other.count) {
        return count > other.count;
    }
    
    const char* firstThis = nullptr;
    const char* firstOther = nullptr;

    for (unsigned i = 0; i < currentCapacity; ++i) {
        if (data[i]) { 
            firstThis = data[i]->getRegistration().toString(); 
            break; 
        }
    }
    
    for (unsigned i = 0; i < other.currentCapacity; ++i) {
        if (other.data[i]) { 
            firstOther = other.data[i]->getRegistration().toString(); 
            break; 
        }
    }
        
    if (!firstThis) {
        return false;
    }
    if (!firstOther) {
        return true;
    }
    return std::strcmp(firstThis, firstOther) > 0;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list) {
    for (unsigned i = 0; i < list.currentCapacity; ++i) {
        if (list.data[i]) os << "[" << list.data[i]->getRegistration() << "] ";
        else os << "[*] ";
    }
    return os;
}