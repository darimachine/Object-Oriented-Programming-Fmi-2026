#pragma once
#include "Registration.h"
#include <compare>
#include <iostream>

class Vehicle {
private:
    Registration reg;
    char* description{};
    unsigned prodYear{};
    unsigned horsepower{};

    void free();
    void copyFrom(const Vehicle& other);

public:
    Vehicle(const Registration& reg, const char* description, unsigned prodYear, unsigned horsepower);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    ~Vehicle();

    const Registration& getRegistration() const;

    std::strong_ordering operator<=>(const Vehicle& other) const;
    bool operator==(const Vehicle& other);
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& veh);
};
