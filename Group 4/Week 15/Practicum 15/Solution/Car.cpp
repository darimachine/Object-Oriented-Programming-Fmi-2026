//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "Car.h"

Car::Car(std::string registration, std::string ownerName, std::string brand, std::string model,
    const unsigned int year) : Vehicle(std::move(registration)),
    ownerName(std::move(ownerName)), brand(std::move(brand)), model(std::move(model)), year(year) {
}

std::unique_ptr<Vehicle> Car::clone() const {

    return std::make_unique<Car>(*this);
}
