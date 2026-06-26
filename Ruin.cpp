#include "Ruin.h"

Ruin::Ruin(const std::string& n, Coords c1, int t, std::string civil) : Landmark(n, c1, t), civilization(civil) {}

std::unique_ptr<Landmark> Ruin::clone() const
{
	return std::make_unique<Ruin>(*this);
}

std::string Ruin::getType() const
{
	return "ruin";
}

void Ruin::print() const
{
	std::cout << "(Ruin) Name: " << name << ", Coords: (" << c.x << ", " << c.y << ")" << ", threat level: " << threat << ", civilization: " << civilization << "\n";
}
