#include "Battery.h"

Battery::Battery(unsigned int id, std::string man, std::string desc, int cap, std::string bId)
:CarPart(id, man, desc), capacity(cap), batteryId(bId) {}

void Battery::printInfo(std::ostream& os) const
{
    os << capacity << " Ah";
}
