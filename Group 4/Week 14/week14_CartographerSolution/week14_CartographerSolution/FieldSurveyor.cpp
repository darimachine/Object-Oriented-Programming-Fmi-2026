#include "FieldSurveyor.h"

FieldSurveyor::FieldSurveyor(std::string name, const unsigned yearsExperience, std::string region) :
	Cartographer(std::move(name), yearsExperience), region(std::move(region))
{
}

std::string FieldSurveyor::getRole() const
{
	return std::move(std::string("FieldSurveyor"));
}

void FieldSurveyor::print() const
{
	std::cout << name << " is a " << getRole()
		<< " with " << yearsExperience << " years of experience"
		<< " working in " << region << " region" << std::endl;
}
