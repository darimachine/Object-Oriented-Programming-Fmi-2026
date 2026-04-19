//
// Created by Vanina Laleva on 18.04.26.
//

#include "VehicleList.h"

void VehicleList::copyFrom(const VehicleList &other) {
    if (other.vehicles == nullptr) {
        vehicles = nullptr;
        capacity = 0;
        return;
    }

    for (size_t i = 0; i < other.capacity; i++) {
        vehicles[i] = other.vehicles[i];
    }
    size = other.size;
    capacity = other.capacity;
}

void VehicleList::free() {
    for (size_t i = 0; i < capacity; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
    vehicles = nullptr;
    size = 0;
    capacity = 0;
}

void VehicleList::moveFrom(VehicleList &&other) {
    if (other.vehicles == nullptr) {
        vehicles = nullptr;
        capacity = 0;
        return;
    }

    vehicles = other.vehicles;
    size = other.size;
    capacity = other.capacity;

    other.vehicles = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void VehicleList::resize(size_t newCapacity) {
    Vehicle **newVehicles = new Vehicle *[newCapacity]{nullptr};
    for (size_t i = 0; i < capacity; i++) {
        newVehicles[i] = vehicles[i];
    }
    delete[] vehicles;
    vehicles = newVehicles;
    capacity = newCapacity;
}

VehicleList::VehicleList(size_t capacity) {
    vehicles = new Vehicle *[capacity]{nullptr};
    this->capacity = capacity;
    size = 0;
}

VehicleList::VehicleList(const VehicleList &other) {
    copyFrom(other);
}

VehicleList &VehicleList::operator=(const VehicleList &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

VehicleList::VehicleList(VehicleList &&other) noexcept {
    moveFrom(std::move(other));
}

VehicleList &VehicleList::operator=(VehicleList &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

VehicleList::~VehicleList() {
    free();
}

size_t VehicleList::getCapacity() const {
    return capacity;
}

size_t VehicleList::getSize() const {
    return size;
}

const Vehicle *VehicleList::operator[](size_t index) const {
    if (vehicles[index] == nullptr) {
        return nullptr;
    }
    return vehicles[index];
}

Vehicle *VehicleList::operator[](size_t index) {
    return vehicles[index];
}

bool VehicleList::isInSystem(const Vehicle &vehicle) const {
    for (size_t i = 0; i < capacity; i++) {
        if (vehicles[i] != nullptr) {
            if (*vehicles[i] == vehicle) {
                return true;
            }
        }
    }
    return false;
}

VehicleList &VehicleList::operator+=(const Vehicle &vehicle) {
    if (size >= capacity && !isInSystem(vehicle)) {
        resize(capacity * 2);
    }
    if (!isInSystem(vehicle)) {
        for (size_t i = 0; i < capacity; i++) {
            if (vehicles[i] == nullptr) {
                vehicles[i] = new Vehicle(vehicle);
                size++;
                break;
            }
        }
    }
    return *this;
}

VehicleList &VehicleList::operator-=(const Vehicle &vehicle) {
    if (isInSystem(vehicle)) {
        for (size_t i = 0; i < capacity; i++) {
            if (*vehicles[i] == vehicle) {
                delete vehicles[i];
                size--;
                vehicles[i] = nullptr;
            }
        }
    }
    return *this;
}

VehicleList &VehicleList::operator-=(const Registration &other) {
    for (size_t i = 0; i < capacity; i++) {
        if (vehicles[i] != nullptr) {
            if (vehicles[i]->getRegistration() == other) {
                delete vehicles[i];
                size--;
                vehicles[i] = nullptr;
            }
        }
    }
    return *this;
}

size_t VehicleList::operator()(const char *cityCode) const {
    size_t result = 0;
    for (size_t i = 0; i < capacity; i++) {
        if (vehicles[i] != nullptr) {
            if (strcmp(vehicles[i]->getRegistration().getFirstLetter(), cityCode) == 0) {
                result++;
            }
        }
    }
    return result;
}

VehicleList::operator bool() const {
    if (size != 0) {
        return true;
    }
    return false;
}

bool VehicleList::isFreeSlot(size_t pos) const {
    return vehicles[pos] == nullptr;
}

bool VehicleList::isEmpty() const {
    return size == 0;
}

Vehicle *VehicleList::find(const Registration &reg) const {
    for (size_t i = 0; i < size; i++) {
        if (vehicles[i] != nullptr) {
            if (vehicles[i]->getRegistration() == reg) {
                return vehicles[i];
            }
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const VehicleList &list) {
    for (size_t i = 0; i < list.getCapacity(); i++) {
        os << i + 1 << ". ";
        if (list[i] == nullptr) {
            os << "*" << "\n";
        } else {
            os << *list[i];
        }
    }
    return os;
}

std::strong_ordering operator<=>(const VehicleList &lhs, const VehicleList &rhs) {
    if (lhs.getSize() == rhs.getSize()) {
        return lhs[0]->getRegistration().getCarPlate() <=> rhs[0]->getRegistration().getCarPlate();
    }
    return lhs.getSize() <=> rhs.getSize();
}
