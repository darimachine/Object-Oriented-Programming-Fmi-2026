#include "Cartographer.h"
#include <iostream>

Cartographer::Cartographer(std::string name, const unsigned yearsExperience) :
	name(std::move(name)), yearsExperience(yearsExperience)
{
}

void Cartographer::print() const
{
	
	std::cout << name << " is a " << getRole() 
		<< " with " << yearsExperience << " years of experience" << std::endl;
}
