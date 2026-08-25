#include "Landmark.h"
#include <iostream>

Landmark::Landmark(std::string name, const double x, const double y, const short threatLevel)
	: name(std::move(name)), threatLevel(threatLevel)
{
	coordinates.x = x;
	coordinates.y = y;
}

void Landmark::setThreatLevel(const short threatLevel)
{
	if (threatLevel < 0 || threatLevel > 10) 
		throw std::invalid_argument("Set threat level must be between 0 and 10");
	this->threatLevel = threatLevel;
}

std::string Landmark::getName() const
{
	return name;
}

short Landmark::getThreatLevel() const
{
	return threatLevel;
}

