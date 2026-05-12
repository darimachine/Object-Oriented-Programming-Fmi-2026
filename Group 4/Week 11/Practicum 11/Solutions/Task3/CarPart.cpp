#include "CarPart.h"

size_t CarPart::idGen = 1;

std::ostream& CarPart::printBase(std::ostream& os) const
{
	return os << "(" << id << ") by " << manufacturerName << " - " << description;
}

CarPart::CarPart(std::string manufacturerName, std::string description)
{
	setManufacturer(std::move(manufacturerName));
	setDescription(std::move(description));
	id = idGen++;
}

size_t CarPart::getId() const
{
	return id;
}

void CarPart::setManufacturer(std::string manufacturerName)
{
	if (!manufacturerName.empty())
	{
		this->manufacturerName = manufacturerName;
	}
}

const std::string& CarPart::getManufacturer() const
{
	return manufacturerName;
}

void CarPart::setDescription(std::string description)
{
	if (!description.empty())
	{
		this->description = description;
	}
}

const std::string& CarPart::getDescription() const
{
	return description;
}

std::ostream& operator<<(std::ostream& os, const CarPart& cp)
{
	cp.printBase(os);
	return os;
}
