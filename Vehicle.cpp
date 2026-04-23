#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"

Vehicle::Vehicle(const Registration& registration, const char* description, unsigned year, unsigned power)
	:registration(registration),year(year),power(power)
{
	setDescription(description);
}

void Vehicle::setDescription(const char* description)
{
	if (description == nullptr)
	{
		return;
	}

	delete[]this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

void Vehicle::copyFrom(const Vehicle& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);

	isValidVehicle = other.isValidVehicle;
	year = other.year;
	power = other.power;
}

void Vehicle::moveFrom(Vehicle&& other)
{
	description = other.description;
	year = other.year;
	power = other.power;
	isValidVehicle = other.isValidVehicle;

	other.isValidVehicle = false;
	other.description = nullptr;
	other.year = 0;
	other.power = 0;
}

void Vehicle::free()
{
	delete[]description;
	description = nullptr;

	isValidVehicle = false;
	year = 0;
	power = 0;
}

Vehicle::~Vehicle()
{
	free();
}

Vehicle::Vehicle(const Vehicle& other):registration(other.registration)
{
	copyFrom(other);
}

Vehicle::Vehicle(Vehicle&& other)noexcept :registration(std::move(other.registration))
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
		registration = other.registration;
	}
	return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
		registration = other.registration;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
	os << vehicle.registration << " " << vehicle.description << " "
		<< vehicle.year << " " <<vehicle.power << '\n';
	return os;
}

bool Vehicle::isValid()const
{
	return isValidVehicle;
}

unsigned Vehicle::getYear()const
{
	return year;
}

unsigned Vehicle::getPower()const
{
	return power;
}

const char* Vehicle::getRegistation()const
{
	return registration.getPlate();
}

const char* Vehicle::getRegistationCode()const
{
	return registration.getCode();
}

std::strong_ordering operator<=>(const Vehicle& lhs, const Vehicle& rhs)
{
	auto cmpYear = lhs.getYear() <=> rhs.getYear();

	if (cmpYear != 0)
	{
		return cmpYear;
	}

	return lhs.getPower() <=> rhs.getPower();
}

bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
	return (lhs.getYear() == rhs.getYear()) && (lhs.getPower() == rhs.getPower());
}