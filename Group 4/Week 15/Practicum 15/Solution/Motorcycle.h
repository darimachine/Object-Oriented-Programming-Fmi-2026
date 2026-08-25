//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MOTORCYCLE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MOTORCYCLE_H
#include "Vehicle.h"


class Motorcycle : public Vehicle{

private:
    std::string ownerName;
    unsigned int maxSpeed = 0;

public:

    Motorcycle() = default;
    Motorcycle(std::string registration, std::string ownerName, const unsigned int maxSpeed);

    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;

    ~Motorcycle() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MOTORCYCLE_H
