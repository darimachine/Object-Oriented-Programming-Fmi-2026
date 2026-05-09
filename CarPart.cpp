#include "CarPart.h"

CarPart::CarPart(unsigned int id, std::string name, std::string descriptiom)
: id(id), name(name), descriptiom(descriptiom) {}

std::ostream& operator<<(std::ostream& os, const CarPart& part)
{
	os << "(" << part.id<< ") by " << part.name << " - " <<part.descriptiom << " - ";
	part.printInfo(os);
	return os;
}
