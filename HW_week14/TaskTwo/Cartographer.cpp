#include "Cartographer.h"
#include "Landmark.h"

Cartographer::Cartographer(const std::string& name, int yearsExperience) : name(name), yearsExperience(yearsExperience)
{

}

const std::string& Cartographer::getName() const
{
	return name;
}

int Cartographer::getYearsExperience() const
{
	return yearsExperience;
}

