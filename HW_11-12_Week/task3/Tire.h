#pragma once
#include "CarPart.h"
#include <string>

class Tire : public CarPart
{
private:
	int width;
	int profile;
	int rimSize;
public:
	Tire(unsigned id, std::string manufacturer, std::string description, int width, int profile, int rimSize);
	void printExtended(std::ostream& os) const override;
};

