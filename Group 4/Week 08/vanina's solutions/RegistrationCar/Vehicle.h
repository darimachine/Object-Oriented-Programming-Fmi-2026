//
// Created by Vanina Laleva on 17.04.26.
//

#ifndef REGISTRATIONCAR_VEHICLE_H
#define REGISTRATIONCAR_VEHICLE_H

#include "Registration.h"


class Vehicle {
    Registration &regNumber;
    char *name;
    unsigned int year;
    double horsepower;

public:
    Vehicle() = delete;

    Vehicle(Registration &reg, const char *name, unsigned int year, double horsepower);

    //
    Registration &getRegistration() const;

    char *getName() const;

    unsigned int getYear() const;

    double getHorsepower() const;
};

std::ostream &operator<<(std::ostream &os, const Vehicle &vehicle);

bool operator==(const Vehicle &lhs, const Vehicle &rhs);

std::strong_ordering operator<=>(const Vehicle &lhs, const Vehicle &rhs);


#endif //REGISTRATIONCAR_VEHICLE_H
