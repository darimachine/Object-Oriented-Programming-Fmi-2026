//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLEFACTORY_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLEFACTORY_H
#include <memory>

#include "Vehicle.h"
#include "VehicleConfig.h"


class VehicleFactory {

public:

    static std::unique_ptr<Vehicle> createVehicle(Vehicle::Type type, const VehicleConfig& config);

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLEFACTORY_H
