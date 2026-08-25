//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "Motorcycle.h"

Motorcycle::Motorcycle(std::string registration, std::string ownerName, const unsigned int maxSpeed) :
    Vehicle(std::move(registration)), ownerName(std::move(ownerName)), maxSpeed(maxSpeed) {
}

std::unique_ptr<Vehicle> Motorcycle::clone() const {

    return std::make_unique<Motorcycle>(*this);
}
