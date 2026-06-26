#include "Landmark.h"
#include<stdexcept>

Landmark::Landmark(const string& name, Coordinates coords, unsigned threat):
	coords(coords)
{
	if (name.empty())
	{
		throw invalid_argument("The name cannot be an empty string.");
	}
	this->name = name;

	if (threat < 0 || threat > MAX_THREAT)
	{
		throw invalid_argument("Threat must be between 0-10.");
	}
	this->threat = threat;
}

const string& Landmark::getName()const
{
	return name;
}

Coordinates Landmark::getCoords() const
{
	return coords;
}

unsigned Landmark::getThreat() const
{
	return threat;
}
