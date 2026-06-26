#include "Vehicle.h"

void Vehicle::free()
{
	delete[] this->description;
	this->description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
	this->regNumber = other.regNumber;
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
	this->description[strlen(this->description)] = '\0';
	this->makeYear = other.makeYear;
	this->horsePower = other.horsePower;
}

void Vehicle::moveFrom(Vehicle&& other) noexcept
{
	this->regNumber = other.regNumber;
	other.regNumber = Registration("XX0000XX");
	this->description = other.description;
	other.description = nullptr;
	this->makeYear = other.makeYear;
	other.makeYear = 0;
	this->horsePower = other.horsePower;
	other.horsePower = 0;
}

Vehicle::Vehicle(const Registration& registration, const char* description, int makeYear, int horsePower)
{
	if (!description) return;
	this->regNumber = registration;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
	this->description[strlen(description)] = '\0';
	this->makeYear = makeYear;
	this->horsePower = horsePower;
}

Vehicle::Vehicle(const Vehicle& other)
{
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept
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

Vehicle::~Vehicle()
{
	free();
}

const char* Vehicle::getReg() const
{
	return this->regNumber.c_str();
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
	os << vehicle.regNumber << '\n' << vehicle.description << '\n' << vehicle.makeYear << '\n' << vehicle.horsePower;
	return os;
}

bool operator<(const Vehicle& vehicle1, const Vehicle& vehicle2)
{
	if (vehicle1.makeYear != vehicle2.makeYear)
	{
		return vehicle1.makeYear < vehicle2.makeYear;
	}

	return vehicle1.horsePower < vehicle2.horsePower;
}

bool operator==(const Vehicle& vehicle1, const Vehicle& vehicle2)
{
	return (vehicle1.makeYear == vehicle2.makeYear && vehicle1.horsePower == vehicle2.horsePower);
}

bool operator>(const Vehicle& vehicle1, const Vehicle& vehicle2)
{
	return vehicle2 < vehicle1;
}
