//
// Created by Vanina Laleva on 2.05.26.
//

#ifndef REPAIRMAN_TIRE_H
#define REPAIRMAN_TIRE_H
#include "CarPart.h"


class Tire : public CarPart {
    unsigned weight;
    unsigned profile;
    unsigned diameter;

public:
    Tire(const std::string& manufacturer, const std::string& description,
        unsigned weight, unsigned profile, unsigned diameter);

    friend std::ostream& operator<<(std::ostream& os, const Tire& tire);
};


#endif //REPAIRMAN_TIRE_H