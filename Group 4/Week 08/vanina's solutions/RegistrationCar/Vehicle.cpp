//
// Created by Vanina Laleva on 17.04.26.
//

#include "Vehicle.h"

Vehicle::Vehicle(Registration &reg, const char *name,
                 unsigned int year, double horsepower) : regNumber(reg) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->year = year;
    this->horsepower = horsepower;
}

Registration &Vehicle::getRegistration() const {
    return regNumber;
}

char *Vehicle::getName() const {
    return name;
}

unsigned int Vehicle::getYear() const {
    return year;
}

double Vehicle::getHorsepower() const {
    return horsepower;
}

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle) {
    os << vehicle.getRegistration() << " - \"" << vehicle.getName() << "\"; ";
    os << vehicle.getYear() << "; ";
    os << vehicle.getHorsepower() << "\n";
    return os;
}

bool operator==(const Vehicle &lhs, const Vehicle &rhs) {
    if (lhs.getRegistration() == rhs.getRegistration() &&
        strcmp(lhs.getName(), rhs.getName()) == 0 &&
        lhs.getYear() == rhs.getYear() &&
        lhs.getHorsepower() == rhs.getHorsepower()) {
        return true;
    }
    return false;
}

std::strong_ordering operator<=>(const Vehicle &lhs, const Vehicle &rhs) {
    if (lhs.getYear() == rhs.getYear()) {
        if (lhs.getHorsepower() < rhs.getHorsepower()) {
            return std::strong_ordering::less;
        }
        if (lhs.getHorsepower() > rhs.getHorsepower()) {
            return std::strong_ordering::greater;
        }
        return std::strong_ordering::equal;
    }
    return lhs.getYear() <=> rhs.getYear();
}
