#include "Battery.h"

void Battery::setAmpHours(int ah)
{
   if (ah > 0) amp_hours = ah;
}

void Battery::setBatteryId(const std::string& bId)
{
   batteryId = bId;
}

void Battery::print(std::ostream& os) const
{
    CarPart::print(os);
    os << " - " << amp_hours << " Ah";
}