#include "Ruin.h"
#include <iostream>

Ruin::Ruin(const std::string& name, Coords coords, int threat, const std::string& civilization) : Landmark(name, coords, threat), civilization(civilization)
{

}

std::string Ruin::getType() const
{
	return "Ruin";
}

void Ruin::print() const
{
	std::cout << "Ruin " << name << " (" << coords.x << ", " << coords.y << ")" << " | threat: " << threat << " | civilization: " << civilization << std::endl;
}

std::unique_ptr<Landmark> Ruin::clone() const
{
	return std::make_unique<Ruin>(*this);
}

