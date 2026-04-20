#include "VehicleList.h"
#include <sstream>

void VehicleList::copyFrom(const VehicleList& other) {
    size_ = other.size_;
    capacity_ = other.capacity_;

    vehicles = new Vehicle*[capacity_];
    for (size_t i = 0; i < capacity_; i++) {
        if (other.vehicles[i] != nullptr) {
            vehicles[i] = new Vehicle(*other.vehicles[i]);
        } else {
            vehicles[i] = nullptr;
        }
    }
}

void VehicleList::free() {
    for (size_t i = 0; i < capacity_; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
    vehicles = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void VehicleList::resize() {
    size_t newCapacity = (capacity_ == 0 ? 1 : capacity_ * 2);

    Vehicle** newData = new Vehicle*[newCapacity];
    for (size_t i = 0; i < newCapacity; i++) {
        newData[i] = nullptr;
    }

    for (size_t i = 0; i < capacity_; i++) {
        newData[i] = vehicles[i];
    }

    delete[] vehicles;
    vehicles = newData;
    capacity_ = newCapacity;
}

int VehicleList::findByRegistration(const Registration& reg) const {
    for (int i = 0; i < capacity_; i++) {
        if (vehicles[i] != nullptr && vehicles[i]->getRegistration() == reg) {
            return i;
        }
    }
    return -1;
}

VehicleList::VehicleList() {
    size_=0;
    capacity_ = 0;
    vehicles = nullptr;
}

VehicleList::VehicleList(size_t capacity)
    : size_(0), capacity_(capacity) {
    vehicles = new Vehicle*[capacity_];
    for (size_t i = 0; i < capacity_; i++) {
        vehicles[i] = nullptr;
    }
}

VehicleList::VehicleList(const VehicleList& other) {
    copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

VehicleList::~VehicleList() {
    free();
}

VehicleList& VehicleList::operator+=(const Vehicle& vehicle) {
    if (findByRegistration(vehicle.getRegistration()) != -1) {
        return *this;
    }

for (size_t i = 0; i < capacity_; i++) {
    if (vehicles[i] == nullptr) {
        vehicles[i] = new Vehicle(vehicle);
        size_++;
        return *this;
    }
}
}

VehicleList& VehicleList::operator-=(const Registration& reg) {
    int index = findByRegistration(reg);
    if (index != -1) {
        delete vehicles[index];
        vehicles[index] = nullptr;
        size_--;
    }
    return *this;
}

Vehicle* VehicleList::find(const Registration& reg) {
    int index = findByRegistration(reg);
    if (index == -1) {
        return nullptr;
    }
    return vehicles[index];
}

size_t VehicleList::operator()(const char *cod) const {
        size_t index = 0;
        for (size_t i = 0; i < size_; i++) {
            const char* carNum = vehicles[i]->getRegistration().getCarNum();
            char firstChar = carNum[0];
            char secondChar = carNum[1];

            if ((firstChar == cod[0] && isdigit(secondChar)) || (firstChar == cod[0] && secondChar == cod[1])) {index++;}
        }
        return index;
    }

Vehicle* VehicleList::operator[](size_t index) {
    return vehicles[index];
}

const Vehicle* VehicleList::operator[](size_t index) const {
    return vehicles[index];
}

bool VehicleList::isFreeSlot(size_t pos) const {
    return vehicles[pos] == nullptr;
}

bool VehicleList::isEmpty() const {
    return size_ == 0;
}

size_t VehicleList::size() const {
    return size_;
}

size_t VehicleList::capacity() const {
    return capacity_;
}

VehicleList::operator bool() const {
    return size_ > 0;
}

bool VehicleList::operator<(const VehicleList& other) const {
    if (size_ != other.size_) {
        return size_ < other.size_;
    }

    for (size_t i = 0; i < size_; i++) {
        if (vehicles[i] != nullptr && other.vehicles[i] != nullptr) {
            return vehicles[i]->getRegistration() < other.vehicles[i]->getRegistration();
        }
    }
    return false;
}

bool VehicleList::operator>(const VehicleList& other) const {
    return other < *this;
}


std::ostream& operator<<(std::ostream& os, const VehicleList& list) {
    for (size_t i = 0; i < list.capacity_; i++) {
        if (list.vehicles[i] != nullptr) {
            os << "[" << list.vehicles[i]->getRegistration() << "] ";
        } else {
            os << "[*] ";
        }
    }
    return os;
}