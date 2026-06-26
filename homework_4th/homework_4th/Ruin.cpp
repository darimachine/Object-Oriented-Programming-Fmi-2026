#include "Ruin.h"
#include <print>
Ruin::Ruin(const std::string& inpName, const Coordinates& inpCoords,
	unsigned int inpThreat, const std::string inpCivilization): Landmark(inpName, inpCoords, inpThreat)
	,civilization(inpCivilization)
{
}

std::string Ruin::getType() const
{
	return "ruin";
}

void Ruin::print() const
{
	Landmark::print();
	std::println("civilization: {}", civilization);
}
