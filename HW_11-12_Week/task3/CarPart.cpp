#include "CarPart.h"
#include <stdexcept>
#include <iostream>
#include "CarPartException.h"

CarPart::CarPart(unsigned id, std::string manufacturer, std::string description) : id(id), manufacturer(manufacturer), description(description)
{
    if (id == 0)
    {
        throw CarPartException("ID must be greater than 0.");
    }
    if (manufacturer.empty())
    {
        throw CarPartException("Manufacturer cannot be empty.");
    }
    if (description.empty())
    {
        throw CarPartException("Description cannot be empty.");
    }
}

std::ostream& operator<<(std::ostream& os, const CarPart& cp)
{
	os << "(" << cp.id << ") by " << cp.manufacturer << " - " << cp.description << " - ";
	cp.printExtended(os);
	return os;
}
