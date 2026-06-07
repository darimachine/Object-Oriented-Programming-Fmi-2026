#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"
#include <cstring>
#include <utility>

void Vehicle::free() {
    delete[] description;
    description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other) {
    this->year = other.year;
    this->power = other.power;

    if (other.description) {
        int len = strlen(other.description);
        this->description = new char[len + 1];
        strcpy(this->description, other.description);
    }
    else {
        this->description = nullptr;
    }
}

void Vehicle::moveFrom(Vehicle&& other) noexcept {
    this->registration = other.registration;
    this->year = other.year;
    this->power = other.power;
    this->description = other.description;

    other.description = nullptr; 
    other.year = 0;
    other.power = 0;
}

Vehicle::Vehicle(const Registration& registration, const char* description, int year, int power)
    : registration(registration), year(year), power(power)
{
    if (description) {
        int len = strlen(description);
        this->description = new char[len + 1];
        strcpy(this->description, description);
    }
    else {
        this->description = nullptr;
    }
}

bool Vehicle::operator==(const Vehicle& other) const
{
    return this->year == other.year && this->power == other.power;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const
{
    if (auto cmp = this->year <=> other.year; cmp != 0) {
        return cmp;
    }

    return this->power <=> other.power;
}

Vehicle::Vehicle(const Vehicle& other) : registration(other.registration) {
    copyFrom(other);
}

Vehicle::Vehicle(Vehicle&& other) noexcept : registration(other.registration) {
    moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        free();
        this->registration = other.registration; 
        copyFrom(other);
    }
    return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Vehicle::~Vehicle() {
    free();
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os << "Vehicle with registration plate: " << vehicle.registration
        << std::endl << "Produced in " << vehicle.year
        << " with " << vehicle.power << " h.p." << std::endl;
    os << (vehicle.description ? vehicle.description : "No description available");

    return os;
}

const Registration& Vehicle::getRegistration() const {
    return registration;
}
