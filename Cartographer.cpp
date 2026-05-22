#include "Cartographer.h"
#include<stdexcept>
#include "Landmark.h"

Cartographer::Cartographer(const string& name, unsigned yearsExperience):
	yearsExperience(yearsExperience)
{
	if (name.empty())
	{
		throw invalid_argument("The name cannot be an empty string.");
	}
	this->name = name;
}

const string& Cartographer::getName() const
{
	return name;
}

unsigned Cartographer::getYearsExperience() const
{
	return yearsExperience;
}
