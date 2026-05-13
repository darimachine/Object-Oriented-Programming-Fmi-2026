#pragma once
#include "Registration.h"

class Vehicle {
private:
    Registration reg;
    char* description;
    int year;
    int power;

    void copyFrom(const Vehicle& other);
    void free();

public:
    Vehicle(const Registration& r, const char* desc, int y, int p);
    
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    ~Vehicle();

    const Registration& getRegistration() const;
    int getYear() const;
    int getPower() const;

    bool operator<(const Vehicle& other) const;
    bool operator>(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
};