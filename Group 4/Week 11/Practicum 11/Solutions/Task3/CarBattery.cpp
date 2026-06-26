#include "CarBattery.h"

CarBattery::CarBattery(std::string manufacturerName, std::string description, unsigned capacity, std::string batteryId) : CarPart(std::move(manufacturerName), std::move(description))
{
    setCapacity(capacity);
    setBatteryId(batteryId);
}

unsigned CarBattery::getCapacity() const
{
    return capacity;
}

void CarBattery::setCapacity(unsigned capacity)
{
    if (capacity > 0) this->capacity = capacity;
}

const std::string& CarBattery::getBatteryId() const
{
    return batteryId;
}

void CarBattery::setBatteryId(std::string batteryId)
{
    if (!batteryId.empty())
    {
        this->batteryId = batteryId;
    }
}

std::ostream& operator<<(std::ostream& os, const CarBattery& cb)
{
    cb.printBase(os) << " - " << cb.capacity << " Ah";
    return os;
}
