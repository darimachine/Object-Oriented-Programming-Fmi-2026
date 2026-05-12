#pragma once
#include "CarPart.h"
class CarBattery : public CarPart
{
	unsigned capacity;
	std::string batteryId;
public:
	CarBattery(std::string manufacturerName, std::string description, unsigned capacity, std::string batteryId);

	unsigned getCapacity() const;
	void setCapacity(unsigned capacity);
	const std::string& getBatteryId() const;
	void setBatteryId(std::string batteryId);

	friend std::ostream& operator<<(std::ostream& os, const CarBattery& cb);
};

