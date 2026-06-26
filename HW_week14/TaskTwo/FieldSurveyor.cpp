#include "FieldSurveyor.h"
#include <iostream>

FieldSurveyor::FieldSurveyor(const std::string& name, int yearsExperience, const std::string& region) : Cartographer(name, yearsExperience), region(region)
{

}

std::string FieldSurveyor::getRole() const
{
	return "Field Surveyor";
}

void FieldSurveyor::print() const
{
	std::cout << "Field Surveyor " << name << " | " << yearsExperience << " years" << " | Region: " << region << std::endl;
}
