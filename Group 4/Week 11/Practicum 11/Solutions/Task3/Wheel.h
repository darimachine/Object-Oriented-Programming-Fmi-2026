#pragma once
#include "CarPart.h"
class Wheel : public CarPart
{
	unsigned width;
	unsigned profile;
	unsigned diameter;
public:
	Wheel(std::string manufacturerName, std::string description, unsigned width, unsigned profile, unsigned diameter);

	unsigned getWidth() const;
	void setWidth(unsigned width);
	unsigned getProfile() const;
	void setProfile(unsigned profile);
	unsigned getDiameter() const;
	void setDiameter(unsigned diameter);

	friend std::ostream& operator<<(std::ostream& os, const Wheel& w);
};

