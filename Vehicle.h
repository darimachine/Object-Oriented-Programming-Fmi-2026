#pragma once
#include "Registration.h"
class Vehicle
{
private:
    Registration registration;
    std::string description;
    unsigned year;
    unsigned horsePower;

public:
    Vehicle(const Registration& reg,
        const std::string& description,
        unsigned year,
        unsigned horsePower);

    const Registration& getRegistration() const;
    const std::string& getDescription() const;
    unsigned getYear() const;
    unsigned getHorsePower() const;

    bool operator==(const Vehicle& other) const;
    bool operator!=(const Vehicle& other) const;
    bool operator<(const Vehicle& other) const;
    bool operator>(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};

