//
// Created by Boris Bozhilov on 4/18/2026.
//

#include <utility>
#include <iostream>
#include "VehicleList.h"

#include <cmath>
#include <cstring>

#include "Utility.h"

// utility functions
bool VehicleList::isValid() const {

    if (capacity <= 0) return false;
    if (size <= 0) return false;
    if (list == nullptr) return false;
    if (size > capacity) return false;
    if (!checkForMatchingRegistrationVehicles()) return false;

    return true;
}

void VehicleList::copyListDataFromOther(const VehicleList &other) {

    if (!other.isValid()) return;
    if (this == &other) return;

    freeListData();

    list = new Vehicle*[other.capacity];

    for (unsigned int i = 0; i < other.capacity; i++) {

        if (other.list[i] == nullptr) {
            list[i] = nullptr;
            continue;
        }

        list[i] = new Vehicle(*other.list[i]);
    }
}

void VehicleList::moveListDataFromOther(VehicleList&& other) {

    if (!other.isValid()) return;
    if (this == &other) return;

    freeListData();

    list = other.list;

    other.list = nullptr;
}

void VehicleList::freeListData() {

    for (unsigned int i = 0; i < capacity; i++) {

        delete list[i];
        list[i] = nullptr;
    }

    delete[] list;
    list = nullptr;
}

bool VehicleList::checkForMatchingRegistrationVehicles() const {

    for (unsigned int i = 0; i < capacity; i++) {

        if (list[i] == nullptr) continue;

        for (unsigned int j = i + 1; j < capacity; j++) {

            if (list[j] == nullptr) continue;

            if (list[i]->getRegistration() == list[j]->getRegistration()) return false;
        }
    }

    return true;
}

// NOTE the function returns false if the vehicle registration is already in the list or the vehicle passed is invalid
// NOTE it saves the available index only if those conditions are true
bool VehicleList::getFirstAvailableIndexInList(const Vehicle &candidateVehicle, unsigned int &availableIndex) const {

    if (!candidateVehicle.isValid()) return false;

    bool availableIndexFoundFlag = false;

    for (unsigned int i = 0; i < capacity; i++) {

        // this ensures that the loop skips the check for registration on nullptr places in the array
        if (list[i] == nullptr) {

            // only the first time we find a nullptr place, its index will be saved in the availableIndex variable
            if (!availableIndexFoundFlag) {
                availableIndex = i;
                availableIndexFoundFlag = true;
            }
            continue;
        }

        // the check for registration is going to be executed only the already included vehicles
        if (list[i]->getRegistration() == candidateVehicle.getRegistration()) return false;
    }

    return true;
}

void VehicleList::enlargeList(const unsigned int newCapacity) {

    Vehicle** enlargedList = new Vehicle*[newCapacity];

    for (unsigned int i = 0; i < capacity; i++) {

        enlargedList[i] = list[i];
    }

    for (unsigned int i = capacity; i < newCapacity; i++) {

        enlargedList[i] = nullptr;
    }

    delete[] list;
    list = enlargedList;

    capacity = newCapacity;
}

std::strong_ordering VehicleList::compareRegistrationOfFirstVehiclesToOther(const VehicleList &other) const {

    Vehicle* vehicle1 = nullptr;
    Vehicle* vehicle2 = nullptr;

    const unsigned int biggerCapacity = capacity > other.capacity ? capacity : other.capacity;
    const unsigned int smallerCapacity = capacity < other.capacity ? capacity : other.capacity;

    for (unsigned int i = 0; i < smallerCapacity; i++) {

        if (vehicle1 == nullptr && list[i] != nullptr) vehicle1 = list[i];
        if (vehicle2 == nullptr && other.list[i] != nullptr) vehicle2 = other.list[i];

        if (vehicle1 != nullptr && vehicle2 != nullptr) break;
    }

    for (unsigned int i = smallerCapacity; i < biggerCapacity; i++) {

        if (vehicle1 == nullptr && list[i] != nullptr) vehicle1 = list[i];
        if (vehicle2 == nullptr && other.list[i] != nullptr) vehicle2 = other.list[i];

        if (vehicle1 != nullptr && vehicle2 != nullptr) break;
    }

    return
    vehicle1->getRegistration().getRegistrationAsString() <=> vehicle2->getRegistration().getRegistrationAsString();
}

bool VehicleList::findIndexOfVehicleInList(const Registration &registration, unsigned int &indexInList) const {

    if (!registration.isValid()) return false;

    for (unsigned int i = 0; i < capacity; i++) {

        if (list[i] == nullptr) continue;

        if (list[i]->getRegistration() == registration) {

            indexInList = i;
            return true;
        }
    }

    return false;
}

// rule of 5
VehicleList::VehicleList() = default;

VehicleList::VehicleList(const unsigned int capacity) : capacity(capacity){

    if (capacity <= 0) return;

    list = new Vehicle*[capacity];

    for (unsigned int i = 0; i < capacity; i++) {
        list[i] = nullptr;
    }
}

VehicleList::VehicleList(const VehicleList &other) {

    if (!other.isValid()) return;

    capacity = other.capacity;
    size = other.size;
    copyListDataFromOther(other);
}

VehicleList &VehicleList::operator=(const VehicleList &other) {

    if (!other.isValid()) return *this;
    if (this == &other) return *this;

    capacity = other.capacity;
    size = other.size;
    copyListDataFromOther(other);

    return *this;
}

VehicleList::VehicleList(VehicleList &&other) noexcept {

    if (!other.isValid()) return;

    capacity = other.capacity;
    size = other.size;

    moveListDataFromOther(std::move(other));

    other.list = nullptr;
    other.capacity = 0;
    other.size = 0;
}

VehicleList &VehicleList::operator=(VehicleList &&other) noexcept {

    if (!other.isValid()) return *this;
    if (this == &other) return *this;

    capacity = other.capacity;
    size = other.size;

    moveListDataFromOther(std::move(other));

    other.list = nullptr;
    other.capacity = 0;
    other.size = 0;

    return *this;
}

// methods
unsigned int VehicleList::getCapacity() const {

    return capacity;
}

unsigned int VehicleList::getSize() const {

    return size;
}

bool VehicleList::isEmpty() const {

    if (capacity == 0) return true;
    if (size == 0) return true;

    return false;
}

bool VehicleList::isFreeSlot(const unsigned int position) const {

    if (position >= capacity) return false;

    return list[position] == nullptr;
}

Vehicle* VehicleList::find(const Registration &registration) const {

    if (!registration.isValid()) return nullptr;

    unsigned int vehicleIndex = 0;

    if (!findIndexOfVehicleInList(registration, vehicleIndex)) return nullptr;

    return list[vehicleIndex];
}

// operators
VehicleList &VehicleList::operator+=(const Vehicle &other) {

    unsigned int availableIndex = 0;

    if (!getFirstAvailableIndexInList(other, availableIndex)) return *this;

    // adding 1 to round up to the bigger number(it helps a little if capacity initially was a single-digit number)
    if (size == capacity) enlargeList(capacity * ENLARGEMENT_RATE + 1);

    list[availableIndex] = new Vehicle(other);
    size++;

    return *this;
}

VehicleList &VehicleList::operator-=(const Registration &vehicleRegistration) {

    unsigned int vehicleIndex;

    if (!findIndexOfVehicleInList(vehicleRegistration, vehicleIndex)) return *this;

    delete list[vehicleIndex];
    list[vehicleIndex] = nullptr;
    size--;

    return *this;
}

unsigned int VehicleList::operator()(const char *locationCode) const {

    const unsigned int codeLength = strlen(locationCode);
    unsigned int countOfMatches = 0;

    // checks if the given code is valid
    if (codeLength > Registration::MAX_LENGTH_LOCATION_CODE) return 0;
    for (unsigned int i = 0; i < codeLength; i++) {

        if (!Utility::isLetter(locationCode[i])) return 0;
    }

    for (unsigned int i = 0; i < capacity; i++) {

        if (list[i] == nullptr) continue;

        bool checkIfMatch = true;

        for (unsigned int j = 0; j < codeLength; j++) {

            if (locationCode[j] != list[i]->getRegistration().getRegistrationAsString()[j]) {

                checkIfMatch = false;
                break;
            }
        }

        if (checkIfMatch) countOfMatches++;
    }

    return countOfMatches;
}

VehicleList::operator bool() const {

    return size > 0;
}

Vehicle VehicleList::operator[](const unsigned int index) const {

    return *list[index];
}

Vehicle &VehicleList::operator[](const unsigned int index) {

    return *list[index];
}

bool VehicleList::operator==(const VehicleList &other) const {

    // check for same size includes both being empty
    if (size == other.size) return true;

    // if one of them has size = 0 then they aren't equal
    if (size == 0 || other.size == 0) return false;

    return compareRegistrationOfFirstVehiclesToOther(other) == 0;
}

std::strong_ordering VehicleList::operator<=>(const VehicleList &other) const {

    if (size != other.size) return size <=> other.size;
    if (size == 0 && other.size == 0) return std::strong_ordering::equal;

    return compareRegistrationOfFirstVehiclesToOther(other);
}

std::ostream &operator<<(std::ostream &output, const VehicleList &list) {

    output << "List of all the vehicles:" << std::endl;

    for (unsigned int i = 0; i < list.capacity; i++) {

        if (list.list[i] == nullptr) {
            output << "*" << std::endl;
            continue;
        }

        output << *list.list[i] << std::endl;
    }

    return output;
}


