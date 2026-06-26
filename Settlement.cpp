#include "Settlement.h"
#include <iostream>

Settlement::Settlement(const std::string& n, Coords c1, int t, int p):Landmark(n, c1, t), population(p) {}

std::unique_ptr<Landmark> Settlement::clone() const
{
	return std::make_unique<Settlement>(*this);
}

std::string Settlement::getType() const
{
	return "settlement";
}

void Settlement::print() const
{
	std::cout << "(Settlement) Name: " << name << ", Coords: (" << c.x << ", " << c.y << ")" << ", threat level: " << threat << ", population: " << population << "\n";
}
