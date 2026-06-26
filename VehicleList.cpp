#include "VehicleList.h"

void VehicleList::resize() {
    unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;

    Vehicle** temp = new Vehicle * [newCapacity] { nullptr };

    for (unsigned i = 0; i < capacity; i++) {
        temp[i] = list[i];
    }

    delete[] list;
    list = temp;
    capacity = newCapacity;
}

void VehicleList::free() {
    for (unsigned i = 0; i < capacity; i++) {
        delete list[i];
    }
    delete[] list;

    list = nullptr;
    size = 0;
    capacity = 0;
}

void VehicleList::copyFrom(const VehicleList& other) {
    capacity = other.capacity;
    size = other.size;

    list = new Vehicle * [capacity] { nullptr };

    for (unsigned i = 0; i < capacity; i++) {
        if (other.list[i]) {
            list[i] = new Vehicle(*other.list[i]);
        }
    }
}

void VehicleList::moveFrom(VehicleList&& other) noexcept {
    list = other.list;
    size = other.size;
    capacity = other.capacity;

    other.list = nullptr;
    other.size = 0;
    other.capacity = 0;
}

VehicleList::VehicleList(unsigned capacity) : capacity(capacity), size(0) {
    list = new Vehicle * [capacity] { nullptr };
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

VehicleList::VehicleList(VehicleList&& other) noexcept {
    moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

VehicleList::~VehicleList() {
    free();
}

VehicleList& VehicleList::operator+=(Vehicle& v) {
    for (unsigned i = 0; i < capacity; i++) {
        if (list[i] && list[i]->getReg() == v.getReg()) {
            return *this;
        }
    }

    if (size == capacity) {
        resize();
    }

    for (unsigned i = 0; i < capacity; i++) {
        if (!list[i]) {
            list[i] = new Vehicle(v);
            size++;
            break;
        }
    }

    return *this;
}

VehicleList& VehicleList::operator-=(const Vehicle& v) {
    for (unsigned i = 0; i < capacity; i++) {
        if (list[i] && list[i]->getReg() == v.getReg()) {
            delete list[i];
            list[i] = nullptr;
            size--;
            break;
        }
    }
    return *this;
}

int VehicleList::operator()(const char* place) const {
    int count = 0;

    for (unsigned i = 0; i < capacity; i++) {
        if (list[i]) {
            const char* plate = list[i]->getReg().getPlate();
            if (strncmp(plate, place, strlen(place)) == 0) {
                count++;
            }
        }
    }

    return count;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& v) {
    for (unsigned i = 0; i < v.capacity; i++) {
        if (v.list[i]) {
            os << *v.list[i] << "\n";
        }
        else {
            os << " * ";
        }
    }
    return os;
}

VehicleList::operator bool() const {
    return size > 0;
}

Vehicle& VehicleList::operator[](size_t index) {
    return *list[index];
}

const Vehicle& VehicleList::operator[](size_t index) const {
    return *list[index];
}

bool VehicleList::isFreeSlot(int pos) const {
    return list[pos] == nullptr;
}

bool VehicleList::isEmpty() const {
    return size == 0;
}

unsigned VehicleList::getCapacity() const {
    return capacity;
}

unsigned VehicleList::getSize() const {
    return size;
}

Vehicle* VehicleList::find(const Registration& reg) {
    for (unsigned i = 0; i < capacity; i++) {
        if (list[i] && list[i]->getReg() == reg) {
            return list[i];
        }
    }
    return nullptr;
}

bool operator==(const VehicleList& lhs, const VehicleList& rhs) {
    if (lhs.getSize() != rhs.getSize()) return false;

    for (unsigned i = 0; i < lhs.getCapacity(); i++) {
        if (lhs.isFreeSlot(i) != rhs.isFreeSlot(i))
            return false;

        if (!lhs.isFreeSlot(i)) {
            if (lhs[i].getReg() != rhs[i].getReg())
                return false;
        }
    }

    return true;
}

bool operator!=(const VehicleList& lhs, const VehicleList& rhs) {
    return !(lhs == rhs);
}

std::strong_ordering operator<=>(const VehicleList& lhs, const VehicleList& rhs) {
    if (lhs.getSize() != rhs.getSize()) {
        return lhs.getSize() <=> rhs.getSize();
    }

    for (unsigned i = 0; i < lhs.getCapacity(); i++) {
        if (lhs.isFreeSlot(i) || rhs.isFreeSlot(i)) continue;

        auto cmp = lhs[i].getReg() <=> rhs[i].getReg();
        if (cmp != 0) return cmp;
    }

    return std::strong_ordering::equal;
}