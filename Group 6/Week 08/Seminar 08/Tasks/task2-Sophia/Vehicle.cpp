#include "Vehicle.h"

void Vehicle::free() {
    delete[] description;
}

void Vehicle::copyFrom(const Vehicle& other) {
    reg = other.reg;
    year = other.year;
    power = other.power;
    description = new char[std::strlen(other.description) + 1];
    std::strcpy(description, other.description);
}

Vehicle::Vehicle(const Registration& r, const char* desc, int y, int p) : reg(r), year(y), power(p) {
    description = new char[std::strlen(desc) + 1];
    std::strcpy(description, desc);
}

Vehicle::~Vehicle() { 
    free(); 
}

Vehicle::Vehicle(const Vehicle& other) : reg(other.reg) { 
    copyFrom(other); 
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

const Registration& Vehicle::getRegistration() const { return reg; }
int Vehicle::getYear() const { 
    return year; 
}
int Vehicle::getPower() const { 
    return power; 
}

bool Vehicle::operator<(const Vehicle& other) const {
    if (year != other.year) {
        return year < other.year;
    }
    return power < other.power;
}

bool Vehicle::operator>(const Vehicle& other) const {
    return other < *this;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << "Vehicle [" << v.reg << "] " << v.description << ", " << v.year << ", " << v.power << "hp";
    return os;
}