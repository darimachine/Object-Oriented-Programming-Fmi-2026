#pragma once
#include <stdexcept>
#include <string>
#include "CarPart.h"

class Battery : public CarPart
{
    int capacity;
    std::string batteryId;
public:
    Battery(unsigned id, std::string manufacturer, std::string description, int cap, std::string bId);
    void printExtended(std::ostream& os) const override;
};

