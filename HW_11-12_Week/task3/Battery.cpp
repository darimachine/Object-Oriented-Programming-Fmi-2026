#include "Battery.h"
#include <iostream>
#include "CarPartException.h"

Battery::Battery(unsigned id, std::string manufacturer, std::string description, int cap, std::string bId) : CarPart(id, manufacturer, description), capacity(cap), batteryId(bId)
{
    if (capacity <= 0)
    {
        throw CarPartException("Battery capacity must be greater than 0.");
    }
    if (capacity > 300)
    {
        throw CarPartException("Battery capacity cannot exceed 300 Ah.");
    }
    if (batteryId.empty())
    {
        throw CarPartException("Battery ID cannot be empty.");
    }
}

void Battery::printExtended(std::ostream& os) const
{
    os << capacity << " Ah | ID: " << batteryId;
}
