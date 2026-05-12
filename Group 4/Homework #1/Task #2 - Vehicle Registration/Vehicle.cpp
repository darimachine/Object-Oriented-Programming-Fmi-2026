//
// Created by Boris Bozhilov on 4/18/2026.
//

#include <utility>
#include <iostream>

#include "Vehicle.h"
#include "Utility.h"

// utility functions
// NOTE for a vehicle to be valid, only its registration number must be valid
bool Vehicle::isValid() const {

    return registration.isValid();
}

void Vehicle::copyVehicleDataFromOther(const Vehicle &other) {

    registration = other.registration;
    Utility::copyStringData(other.description, description);
    yearOfCreation = other.yearOfCreation;
    engineHorsePower = other.engineHorsePower;
}

void Vehicle::moveVehicleDataFromOther(Vehicle&& other) {

    registration = std::move(other.registration);
    Utility::moveStringData(other.description, description);
    yearOfCreation = other.yearOfCreation;
    engineHorsePower = other.engineHorsePower;

    other.description = nullptr;
    other.yearOfCreation = 0;
    other.engineHorsePower = 0;
}

const Registration &Vehicle::getRegistration() const {

    return registration;
}

// rule of 5
Vehicle::Vehicle(const Registration& registration, const char *description,
    const unsigned short yearOfCreation, const unsigned int engineHorsePower) {

    if (!registration.isValid()) return;

    this->registration = registration;
    Utility::copyStringData(description, this->description);
    this->yearOfCreation = yearOfCreation;
    this->engineHorsePower = engineHorsePower;
}

Vehicle::Vehicle(const Vehicle &other) {

    if (!other.isValid()) return;

    copyVehicleDataFromOther(other);
}

Vehicle &Vehicle::operator=(const Vehicle &other) {

    if (this == &other) return *this;
    if (!other.isValid()) return *this;

    copyVehicleDataFromOther(other);

    return *this;
}

Vehicle::Vehicle(Vehicle &&other) {

    if (!other.isValid()) return;

    moveVehicleDataFromOther(std::move(other));
}

Vehicle &Vehicle::operator=(Vehicle &&other) {

    if (this == &other) return *this;
    if (!other.isValid()) return *this;

    moveVehicleDataFromOther(std::move(other));

    return *this;
}

Vehicle::~Vehicle() {

    delete[] description;
    description = nullptr;
    yearOfCreation = 0;
    engineHorsePower = 0;
}

// operators
bool Vehicle::operator==(const Vehicle &other) const {

    if (yearOfCreation == other.yearOfCreation) return engineHorsePower == other.engineHorsePower;
    return yearOfCreation == other.yearOfCreation;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle &other) const {

    if (yearOfCreation == other.yearOfCreation) return engineHorsePower <=> other.engineHorsePower;
    return yearOfCreation <=> other.yearOfCreation;
}

std::ostream &operator<<(std::ostream &output, const Vehicle &vehicle) {

    output << "Vehicle information:" << std::endl;
    output << "Registration #: " << vehicle.registration << std::endl;
    output << "Description: " << vehicle.description << std::endl;
    output << "Year of creation: " << vehicle.yearOfCreation << std::endl;
    output << "Horse power: " << vehicle.engineHorsePower << std::endl;

    return output;
}
