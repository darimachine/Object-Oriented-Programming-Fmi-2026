#include "Settlement.h"
#include <iostream>

Settlement::Settlement(const std::string& name, Coords coords, int threat, int population) : Landmark(name, coords, threat), population(population)
{

}

std::string Settlement::getType() const
{
	return "Settlement";
}

void Settlement::print() const
{
    std::cout << "Settlement " << name << " (" << coords.x << ", " << coords.y << ")" << " | threat: " << threat << " | population: " << population << std::endl;
}

std::unique_ptr<Landmark> Settlement::clone() const
{
	return std::make_unique<Settlement>(*this);
}

