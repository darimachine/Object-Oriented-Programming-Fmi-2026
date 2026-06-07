#include "VehicleList.h"

void VehicleList::free() {
    for (int i = 0; i < capacity_; i++) delete vehicles[i];
    delete[] vehicles;
}

void VehicleList::copyFrom(const VehicleList& other) {
    capacity_ = other.capacity_;
    size_ = other.size_;
    vehicles = new Vehicle * [capacity_];
    for (int i = 0; i < capacity_; i++) {
        if (other.vehicles[i]) vehicles[i] = new Vehicle(*other.vehicles[i]);
        else vehicles[i] = nullptr;
    }
}

void VehicleList::moveFrom(VehicleList&& other) noexcept {
    vehicles = other.vehicles;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.vehicles = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

void VehicleList::resize() {
    int oldCap = capacity_;
    capacity_ *= 2;
    Vehicle** temp = new Vehicle * [capacity_];
    for (int i = 0; i < capacity_; i++) {
        if (i < oldCap) temp[i] = vehicles[i];
        else temp[i] = nullptr;
    }
    delete[] vehicles;
    vehicles = temp;
}

VehicleList::VehicleList(int capacity) : size_(0), capacity_(capacity > 0 ? capacity : 8) {
    vehicles = new Vehicle * [capacity_];
    for (int i = 0; i < capacity_; i++) vehicles[i] = nullptr;
}

VehicleList::~VehicleList() 
{ 
    free(); 
}

VehicleList::VehicleList(const VehicleList& other) 
{ 
    copyFrom(other); 
}

VehicleList::VehicleList(VehicleList&& other) noexcept 
{ 
    moveFrom(std::move(other)); 
}

VehicleList& VehicleList::operator=(const VehicleList& other) {
    if (this != &other) 
    { 
        free();
        copyFrom(other); 
    }

    return *this;
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept {
    if (this != &other) 
    { 
        free(); 
        moveFrom(std::move(other)); 
    }

    return *this;
}

Vehicle* VehicleList::find(const char* reg) const {
    for (int i = 0; i < capacity_; i++) {
        if (vehicles[i] && strcmp(vehicles[i]->getRegistration().getRegistration(), reg) == 0) return vehicles[i];
    }
    return nullptr;
}

void VehicleList::operator+=(const Vehicle& v) {
    if (find(v.getRegistration().getRegistration())) return;
    if (size_ >= capacity_) resize();
    for (int i = 0; i < capacity_; i++) {
        if (!vehicles[i]) {
            vehicles[i] = new Vehicle(v);
            size_++;
            return;
        }
    }
}

void VehicleList::operator-=(const char* reg) {
    for (int i = 0; i < capacity_; i++) {
        if (vehicles[i] && strcmp(vehicles[i]->getRegistration().getRegistration(), reg) == 0) {
            delete vehicles[i];
            vehicles[i] = nullptr;
            size_--;
            return;
        }
    }
}

int VehicleList::operator()(const char* code) const {
    int count = 0;
    int len = strlen(code);
    for (int i = 0; i < capacity_; i++) {
        if (vehicles[i] && strncmp(vehicles[i]->getRegistration().getRegistration(), code, len) == 0) count++;
    }
    return count;
}

Vehicle* VehicleList::operator[](int index) {
    return (index >= 0 && index < capacity_) ? vehicles[index] : nullptr;
}

const Vehicle* VehicleList::operator[](int index) const {
    return (index >= 0 && index < capacity_) ? vehicles[index] : nullptr;
}

bool VehicleList::isFreeSlot(int pos) const {
    return (pos >= 0 && pos < capacity_) && !vehicles[pos];
}

bool VehicleList::operator==(const VehicleList& other) const
{
    if (this->size_ != other.size_) {
        return false;
    }
   
    Vehicle* firstThis = nullptr;

    for (size_t i = 0; i < this->size_; i++)
    {
        if (isFreeSlot(i))
        {
            continue;
        }
        else
        {
            firstThis = vehicles[i];
            break;
        }
    }

    Vehicle* firstOther = nullptr;

    for (size_t i = 0; i < other.size_; i++)
    {
        if (isFreeSlot(i))
        {
            continue;
        }
        else
        {
            firstOther = vehicles[i];
            break;
        }
    }

    return *firstThis == *firstOther;
}

std::strong_ordering VehicleList::operator<=>(const VehicleList& other) const {
    if (auto cmp = size_ <=> other.size_; cmp != 0)
    {
        return cmp;
    }

    Vehicle* f1 = nullptr;
    Vehicle* f2 = nullptr;

    for (int i = 0; i < capacity_; i++)
    {
        if (vehicles[i])
        {
            f1 = vehicles[i]; break;
        }
    }
    for (int i = 0; i < other.capacity_; i++) {
        if (other.vehicles[i]) 
        {
            f2 = other.vehicles[i]; break;
        }
    }

    if (!f1 && !f2) 
    {
        return std::strong_ordering::equal;
    }
    if (!f1) 
    { 
        return std::strong_ordering::less;
    }
    if (!f2)
    {
        return std::strong_ordering::greater;
    }

    return strcmp(f1->getRegistration().getRegistration(), f2->getRegistration().getRegistration()) <=> 0;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& vl) {
    for (int i = 0; i < vl.capacity_; i++) {
        if (!vl.vehicles[i]) os << "*\n";
        else os << *vl.vehicles[i] << "\n";
    }
    return os;
}