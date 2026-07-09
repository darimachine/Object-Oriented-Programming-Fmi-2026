
#pragma once
#include "CarPart.h"

class Battery : public CarPart {
private:
    int amp_hours;
    std::string batteryId;
public:

    void setAmpHours(int ah); 
    void setBatteryId(const std::string& bId);
    void print(std::ostream& os) const override;
};