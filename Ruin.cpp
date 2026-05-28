#include "Ruin.h"

Ruin::Ruin(const std::string& name, const Coords& coords, int threat, const std::string& civilization)
	: Landmark(name, coords, threat), civilization(civilization)
{}

std::string Ruin::getType() const
{
	return "Ruin";
}

void Ruin::print() const
{
	Landmark::print();
	std::cout << " | Ancient Civilization: " << civilization << "\n";
}

