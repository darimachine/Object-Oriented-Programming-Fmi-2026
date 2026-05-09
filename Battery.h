#pragma once
#include "CarPart.h"

class Battery : public CarPart {
	int capacity;
	std::string batteryId;

	public:
	Battery(unsigned int id, std::string man, std::string desc, int cap, std::string bId);
	void printInfo(std::ostream& os) const override;
};
