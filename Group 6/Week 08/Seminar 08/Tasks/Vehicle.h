#pragma once
#include "Registration.h"

class Vehicle {
    Registration registration_;
    char* description;
    unsigned int year;
    int power;
    void copyFrom(const Vehicle& other);
    void free();
    public:
    Vehicle(const Registration& reg,const char* description_, unsigned long year_, int power_);
    ~Vehicle();
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);

    bool operator<(const Vehicle& other) const;
    bool operator>(const Vehicle& other) const;
     const Registration& getRegistration() const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& car);
};
std::ostream& operator<<(std::ostream& os, const Vehicle& car);

