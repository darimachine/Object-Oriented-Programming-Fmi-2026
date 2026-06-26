#include "Settlement.h"
#include <print>
Settlement::Settlement(const std::string& inpName, const Coordinates& inpCoords, 
	unsigned int inpThreat, unsigned int inpPopulation) : Landmark(inpName, inpCoords, inpThreat),
	population(inpPopulation)
{
}

std::string Settlement::getType() const
{
	return "Settlement";
}

void Settlement::print() const
{
	Landmark::print();
	std::println("population: {}, type: {}", population, getType());
}
