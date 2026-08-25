//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAR_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAR_H
#include "Vehicle.h"


class Car : public Vehicle{

private:
    std::string ownerName;
    std::string brand;
    std::string model;
    unsigned int year = 0;

public:

    Car() = default;
    Car(std::string registration, std::string ownerName, std::string brand, std::string model,
        const unsigned int year);

    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;

    ~Car() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CAR_H
