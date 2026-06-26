//
// Created by Vanina Laleva on 2.05.26.
//

#include "Accumulator.h"

Accumulator::Accumulator(unsigned ampHours, unsigned long batteryId, const std::string& manufacturer,
        const std::string& description) : CarPart(manufacturer, description) {
    this->ampHours = ampHours;
    this->batteryId = batteryId;
}

std::ostream & operator<<(std::ostream &os, const Accumulator &acc) {
    os << (CarPart) acc;
    os << acc.ampHours << " Ah";
    return os;
}
