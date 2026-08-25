//
// Created by Boris Bozhilov on 5/30/2026.
//

#include "VehicleFactory.h"

#include "Car.h"
#include "Motorcycle.h"
#include "Train.h"

std::unique_ptr<Vehicle> VehicleFactory::createVehicle(const Vehicle::Type type, const VehicleConfig& config) {

    switch (type) {

        case Vehicle::Type::Car: {

            return std::make_unique<Car>
            (config.registration, config.ownerName_CAR, config.brand_CAR, config.model_CAR, config.year_CAR);
        }
        case Vehicle::Type::Motorcycle: {

            return std::make_unique<Motorcycle>
            (config.registration, config.ownerName_MOTORCYCLE, config.maxSpeed_MOTORCYCLE);
        }
        case Vehicle::Type::Train: {

            return std::make_unique<Train>
            (config.registration, config.mechanicsCount_TRAIN, config.wagonCount_TRAIN,
                config.seatsCount_TRAIN, config.standingCount_TRAIN);
        }
        default: {

            throw std::invalid_argument("An invalid type has been selected");

            // just in case
            return nullptr;
        }
    }
}
