#pragma once
#include "Registration.h"
class Vehicle
{
private:
    Registration registration;
    char* description;
    unsigned year;
    unsigned horsepower;

    void free();
    void copyFrom(const Vehicle& other);
    void moveFrom(Vehicle&& other) noexcept;

public:
    Vehicle() = delete;
    Vehicle(const Registration& reg, const char* description, unsigned year, unsigned hp);

    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    Vehicle(Vehicle&& other) noexcept;
    Vehicle& operator=(Vehicle&& other) noexcept;
    ~Vehicle();

    const Registration& getRegistration() const;
    const char* getDescription() const;
    unsigned getYear() const;
    unsigned getHorsepower() const;

    std::strong_ordering operator<=>(const Vehicle& other) const;
    bool operator==(const Vehicle& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
};

