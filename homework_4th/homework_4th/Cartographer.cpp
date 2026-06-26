#include "Cartographer.h"
#include <print>
Cartographer::Cartographer(const std::string& inpName, unsigned int inpYearsExp) : 
	name(inpName), yearsOfExperience(inpYearsExp)
{
}

void Cartographer::printInfo() const
{
	std::print("Name: {}, yearsOfexperience: {}", name, yearsOfExperience);
}
