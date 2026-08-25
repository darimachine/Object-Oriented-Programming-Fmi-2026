//
// Created by Boris Bozhilov on 5/31/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLECONFIG_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLECONFIG_H

#include <string>


struct VehicleConfig {

    std::string registration;

    std::string ownerName_CAR;
    std::string brand_CAR;
    std::string model_CAR;
    unsigned int year_CAR = 0;

    std::string ownerName_MOTORCYCLE;
    unsigned int maxSpeed_MOTORCYCLE = 0;

    unsigned int mechanicsCount_TRAIN = 0;
    unsigned int wagonCount_TRAIN = 0;
    unsigned int seatsCount_TRAIN = 0;
    unsigned int standingCount_TRAIN = 0;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLECONFIG_H
