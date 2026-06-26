#include "FieldSurveyor.h"
#include <print>
FieldSurveyor::FieldSurveyor(const std::string& inpName, unsigned int inpYExp, 
							 const std::string& region):
	Cartographer(inpName, inpYExp), region(region)
{
}

void FieldSurveyor::printInfo() const
{
	Cartographer::printInfo();
	std::print(" region: {} ",region);
}

 std::string FieldSurveyor::getRole() const
{
	return "Field Surveyor";
}
