#include "VehicleList.h"

#include <cstring>

void VehicleList::free() {
    for (int i = 0; i < cap; i++) {
        delete slots[i];
    }
    delete[] slots;
    slots = nullptr;
}

void VehicleList::copyFrom(const VehicleList &other) {
    cap = other.cap;
    count = other.count;
    slots = new Vehicle*[cap];
    for (int i = 0; i < cap; i++) {
        slots[i] = other.slots[i] ? new Vehicle(*other.slots[i]) : nullptr;
    }
}

void VehicleList::resize() {
    unsigned newCap = cap * 2;
    Vehicle** newSlots = new Vehicle*[newCap];
    for (int i = 0; i < cap; i++) {
        newSlots[i] = slots[i];
    }
    for (int i = cap; i < newCap; i++) {
        newSlots[i] = nullptr;
    }
    delete[] slots;
    slots = newSlots;
    cap = newCap;
}

VehicleList::VehicleList(unsigned capacity) : cap(capacity), count(0) {
    slots = new Vehicle*[cap];
    for (int i = 0; i < cap; i++) {
        slots[i] = nullptr;
    }
}

VehicleList::VehicleList(const VehicleList &other) {
    copyFrom(other);
}

VehicleList & VehicleList::operator=(const VehicleList &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

VehicleList::~VehicleList() {
    free();
}

VehicleList & VehicleList::operator+=(const Vehicle &veh) {
    if (find(veh.getRegistration())) {
        return *this;
    }

    for (int i = 0; i < cap; i++) {
        if (!slots[i]) {
            slots[i] = new Vehicle(veh);
            count++;
            return *this;
        }
    }

    resize();
    for (int i = 0; i < cap; i++) {
        if (!slots[i]) {
            slots[i] = new Vehicle(veh);
            count++;
            return *this;
        }
    }

    return *this;
}

VehicleList & VehicleList::operator-=(const Registration &reg) {
    for (int i = 0; i < cap; i++) {
        if (slots[i] && slots[i]->getRegistration() == reg) {
            delete slots[i];
            slots[i] = nullptr;
            count--;
            return *this;
        }
    }

    return *this;
}

std::strong_ordering VehicleList::operator<=>(const VehicleList &other) const {
    if (auto cmp = count <=> other.count; cmp != 0) {
        return cmp;
    }

    const Vehicle* x = nullptr;
    const Vehicle* y = nullptr;
    for (int i = 0; i < cap && !x; i++) {
        if (slots[i]) {
            x = slots[i];
        }
    }
    for (int i = 0; i < other.cap && !y; i++) {
        if (other.slots[i]) {
            y = other.slots[i];
        }
    }

    if (!x && !y) {
        return std::strong_ordering::equal;
    }
    if (!x) {
        return std::strong_ordering::less;
    }
    if (!y) {
        return std::strong_ordering::greater;
    }

    return x->getRegistration() <=> y->getRegistration();
}

bool VehicleList::operator==(const VehicleList &other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}

unsigned VehicleList::operator()(const char *cityCode) const {
    if (!cityCode) {
        return 0;
    }
    int len = strlen(cityCode);
    int result = 0;
    for (int i = 0; i < cap; i++) {
        if (!slots[i]) {
            continue;;
        }
        const char* plate = slots[i]->getRegistration().getPlate();
        if (strncmp(plate, cityCode, len) == 0 && plate[len] >= '0' && plate[len] <= '9') {
            result++;
        }
    }

    return result;
}

VehicleList::operator bool() const {
    return count > 0;
}

Vehicle * VehicleList::operator[](unsigned index) {
    return (index < cap) ? slots[index] : nullptr;
}

const Vehicle * VehicleList::operator[](unsigned index) const {
    return (index < cap) ? slots[index] : nullptr;
}

bool VehicleList::isFreeSlot(unsigned pos) const {
    return pos < cap && slots[pos] == nullptr;
}

bool VehicleList::isEmpty() const {
    return count == 0;
}

unsigned VehicleList::capacity() const {
    return cap;
}

unsigned VehicleList::size() const {
    return count;
}

Vehicle * VehicleList::find(const Registration &reg) const {
    for (int i = 0; i < cap; i++) {
        if (slots[i] && slots[i]->getRegistration() == reg) {
            return slots[i];
        }
    }
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const VehicleList &vehlist) {
    for (int i = 0; i < vehlist.cap; i++) {
        if (vehlist.slots[i]) {
            os << vehlist.slots[i]->getRegistration() << '\n';
        }
        else {
            os << "Empty";
        }
    }
    return os;
}
