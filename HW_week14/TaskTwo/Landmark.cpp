#include "Landmark.h"
#include <stdexcept>

Landmark::Landmark(const std::string& name, Coords coords, int threat) : name(name), coords(coords), threat(threat)
{
	if (threat < 0 || threat > 10)
	{
		throw std::invalid_argument("Threat level must be between 0 and 10.");
	}
}

const std::string& Landmark::getName() const 
{ 
	return name;
}

Coords Landmark::getCoords() const
{
	return coords;
}

int Landmark::getThreat() const
{
	return threat;
}