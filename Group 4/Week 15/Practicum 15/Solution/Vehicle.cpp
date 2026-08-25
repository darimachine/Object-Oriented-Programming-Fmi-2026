//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(std::string registration) : registration(std::move(registration)){
}

const std::string& Vehicle::getRegistration() const {

    return registration;
}

void Vehicle::print(std::ostream &output) {

    output << registration << std::endl;
}
