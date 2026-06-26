#include "CarPart.h"
#include <iostream>
unsigned CarPart::ID = 1;

CarPart::CarPart(const std::string& inpMName, const std::string& inpDesc): manifacturerName(inpMName), description(inpDesc)
{
	partID = ID;
	ID++;
}

void CarPart::print(std::ostream& os) const
{
	os << partID << " by " << manifacturerName<<" - " << description << " - ";
}

std::ostream& operator<<(std::ostream& os, const CarPart& obj)
{
	obj.print(os);
	return os;
}
