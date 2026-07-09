#include "Vehicle.h"

Vehicle::Vehicle(Registration& reg, const char* description, short year, short hp) : registrion(reg), year(year), hp(hp)
{
	//if (reg)
	//	throw std::invalid_argument("Invalid registration input parameter.");
	if (year < 1700 || year > 2026)
		throw std::invalid_argument("Invalid year input parameter.");
	if (hp < 0 || hp > 3000)
		throw std::invalid_argument("Invalid horse power input parameter.");

	if (description)
	{
		this->description = new char[std::strlen(description) + 1];
		std::strcpy(this->description, description);
	}
}

Vehicle::Vehicle(const Vehicle& other) : registrion(other.registrion), year(other.year), hp(other.hp)
{
	description = new char[std::strlen(other.description) + 1];
	std::strcpy(description, other.description);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		delete[] description;

		registrion = other.registrion;
		year = other.year;
		hp = other.hp;

		description = new char[std::strlen(other.description) + 1];
		std::strcpy(this->description, other.description);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	delete[] description;
}

Registration& Vehicle::getRegistration() const
{
	return registrion;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const
{
	if (auto cmp = year <=> other.year; cmp != 0)
	{
		return cmp;
	}

	return hp <=> other.hp;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v)
{
	os << "Vehicle: \n";
	os << "-----------------------\n";
	os << v.registrion;
	os << "Description: " << v.description << std::endl;
	os << "Year: " << v.year << std::endl;
	os << "Horse powers: " << v.hp << std::endl;
	os << "-----------------------\n";

	return os;
}

