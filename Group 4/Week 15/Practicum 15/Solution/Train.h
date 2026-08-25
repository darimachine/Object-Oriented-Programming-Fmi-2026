//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TRAIN_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TRAIN_H
#include "Vehicle.h"


class Train : public Vehicle{

private:
    unsigned int mechanicsCount = 0;
    unsigned int wagonCount = 0;
    unsigned int seatsCount = 0;
    unsigned int standingCount = 0;

public:

    Train() = default;
    Train(std::string registration, const unsigned int mechanicsCount, const unsigned int wagonCount,
        const unsigned int seatsCount, const unsigned int standingCount);

    [[nodiscard]] std::unique_ptr<Vehicle> clone() const override;

    ~Train() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_TRAIN_H
