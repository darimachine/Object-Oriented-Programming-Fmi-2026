#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include <cstring>

void Vehicle::free()
{
	delete[] description;
	description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
	year = other.year;
	horsepower = other.horsepower;
}

void Vehicle::moveFrom(Vehicle&& other) noexcept
{
	registration = other.registration;
	description = other.description;
	year = other.year;
	horsepower = other.horsepower;
	other.description = nullptr;
}

Vehicle::Vehicle(const Registration& reg, const char* desc, unsigned year, unsigned hp)
	: registration(reg), year(year), horsepower(hp)
{
	if (!desc)
	{
		desc = "";
	}
	if (year < 1885 || year > 2026)
	{
		this->year = 0;
	}
	if (hp == 0)
	{
		this->horsepower = 0;
	}

	description = new char[strlen(desc) + 1];
	strcpy(description, desc);
}

Vehicle::Vehicle(const Vehicle& other)
	: registration(other.registration),
	year(other.year),
	horsepower(other.horsepower)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		registration = other.registration;
		copyFrom(other);
	}
	return *this;
}

Vehicle::~Vehicle()
{
	free();
}

Vehicle::Vehicle(Vehicle&& other) noexcept : registration(other.registration), description(other.description),
year(other.year), horsepower(other.horsepower)
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

const Registration& Vehicle::getRegistration() const
{
	return registration;
}
const char* Vehicle::getDescription() const
{
	return description;
}
unsigned Vehicle::getYear() const
{
	return year;
}
unsigned Vehicle::getHorsepower() const
{
	return horsepower;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const
{
	if (year != other.year)
	{
		return year <=> other.year;
	}
	return horsepower <=> other.horsepower;
}

bool Vehicle::operator==(const Vehicle& other) const
{
	return (registration == other.registration);
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v)
{
	os << v.registration << " "
		<< v.description
		<< " | Year: " << v.year
		<< " | HP: " << v.horsepower;
	return os;
}