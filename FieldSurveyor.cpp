#include "FieldSurveyor.h"

FieldSurveyor::FieldSurveyor(const std::string& name, int yearsExperience, const std::string& fieldServeyor)
	: Cartographer(name, yearsExperience), fieldServeyor(fieldServeyor) 
{}

std::string FieldSurveyor::getRole() const
{
	return "Field Surveyor";
}

void FieldSurveyor::print() const
{
	Cartographer::print();
	std::cout << ", Specialization Region: " << fieldServeyor << "\n";
}
