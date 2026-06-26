//
// Created by Vanina Laleva on 2.05.26.
//

#ifndef REPAIRMAN_ACCUMULATOR_H
#define REPAIRMAN_ACCUMULATOR_H
#include "CarPart.h"


class Accumulator : public CarPart {
    unsigned ampHours;
    unsigned long batteryId;

public:
    Accumulator(unsigned ampHours, unsigned long batteryId, const std::string& manufacturer,
        const std::string& description);

    friend std::ostream& operator<<(std::ostream& os, const Accumulator& acc);
};


#endif //REPAIRMAN_ACCUMULATOR_H