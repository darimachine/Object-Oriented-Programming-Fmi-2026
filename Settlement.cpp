#include "Settlement.h"

Settlement::Settlement(const std::string& name, const Coords& coords, int threat, int population)
	: Landmark(name, coords, threat), population(population)
{}

std::string Settlement::getType() const 
{
	return "Settlement";
}

void Settlement::print() const
{
	Landmark::print();
	std::cout << " | Population: " << population << "\n";
}

