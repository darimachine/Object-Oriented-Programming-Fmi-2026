#include "Vehicle.h"

#include <cstring>

void Vehicle::free() {
    delete[] description;
    description = nullptr;
}

void Vehicle::copyFrom(const Vehicle &other) {
    reg = other.reg;
    prodYear = other.prodYear;
    horsepower = other.horsepower;
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

Vehicle::Vehicle(const Registration &reg, const char *description, unsigned prodYear, unsigned horsepower) : reg(reg), prodYear(prodYear), horsepower(horsepower) {
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Vehicle::Vehicle(const Vehicle &other) : reg(other.reg), description(nullptr), prodYear(other.prodYear), horsepower(other.horsepower) {
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

Vehicle & Vehicle::operator=(const Vehicle &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::~Vehicle() {
    free();
}

const Registration & Vehicle::getRegistration() const {
    return reg;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle &other) const {
    if (auto cmp = prodYear <=> other.prodYear; cmp != 0) {
        return cmp;
    }
    return horsepower <=> other.horsepower;
}

bool Vehicle::operator==(const Vehicle &other) {
    return prodYear == other.prodYear && horsepower == other.horsepower && reg == other.reg;
}

std::ostream & operator<<(std::ostream &os, const Vehicle &veh) {
    os << "Registration Number: " << veh.reg << '\n'
       << "Description: " << veh.description << '\n'
       << "Production Year: " << veh.prodYear << '\n'
       << "Horsepower: " << veh.horsepower << '\n';
    return os;
}
