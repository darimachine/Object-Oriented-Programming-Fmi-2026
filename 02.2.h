#pragma once
#pragma once
#include "02.1.h"
#include <iostream>
#include <compare>

class Vehicle {
private:
    Registration carNum;
    char* text;
    int year;
    double power;

    void copyFrom(const Vehicle& other);
    void free();

public:
    Vehicle(const Registration& reg, const char* description, int year, double power);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;
    ~Vehicle();

    const char* getRegNum() const;

    std::strong_ordering operator<=>(const Vehicle& other) const;
    bool operator==(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
};