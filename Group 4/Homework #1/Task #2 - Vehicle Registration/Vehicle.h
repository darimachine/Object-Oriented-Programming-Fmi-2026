//
// Created by Boris Bozhilov on 4/18/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
#include "Registration.h"


class Vehicle {

private:

    Registration registration = Registration(nullptr);
    char* description = nullptr;
    unsigned short yearOfCreation = 0;
    unsigned int engineHorsePower = 0;

public:

    // utility functions
    bool isValid() const;
    void copyVehicleDataFromOther(const Vehicle& other);
    void moveVehicleDataFromOther(Vehicle&& other);
    const Registration& getRegistration() const;

    // rule of 5
    Vehicle() = delete;
    Vehicle(const Registration& registration, const char* description,
        const unsigned short yearOfCreation, const unsigned int engineHorsePower);

    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);

    Vehicle(Vehicle&& other);
    Vehicle& operator=(Vehicle&& other);

    ~Vehicle();

    // operators
    bool operator==(const Vehicle& other) const;
    std::strong_ordering operator<=>(const Vehicle& other) const;
    friend std::ostream& operator<<(std::ostream& output, const Vehicle& vehicle);
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
