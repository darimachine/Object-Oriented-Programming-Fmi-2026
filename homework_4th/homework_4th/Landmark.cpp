#include "Landmark.h"
#include <print>
Landmark::Landmark(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat)
	:name(inpName), coords(inpCoords), threat(inpThreat)
{
	if (threat > MAX_THREAT)
	{
		throw std::invalid_argument("The threat can not be more than 10!");
	}
}

void Landmark::print() const
{
	std::print("Name: {}, coordinates: x: {}, y: {}, threat: {}", name, coords.x, coords.y, threat);
}

const std::string& Landmark::getName() const
{
	return name;
}
