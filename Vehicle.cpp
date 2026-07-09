#include "Vehicle.h"
#include <cstring>
#include "Utils.h"

void Vehicle::copyFrom(const Vehicle& other)
{
	year = other.year;
	power = other.power;
	isValidVehicle = other.isValidVehicle;
	description = Utils::copyDynamicString(other.description);
}

void Vehicle::free()
{
	delete[] description;
	description = nullptr;
}

void Vehicle::moveFrom(Vehicle&& other)
{
	year = other.year;
	power = other.power;
	description = other.description;
	isValidVehicle = other.isValidVehicle;

	other.year = 0;
	other.power = 0;
	other.description = nullptr;
	other.isValidVehicle = false;
}

Vehicle::Vehicle(const Registration& plateStr, const char* descr, int year, int power):registration(plateStr)
{
	if (!descr || year < 1886 || power == 0 || power > 2000) {
		isValidVehicle = false;
		description = Utils::copyDynamicString("");
		this->year = 0;
		this->power = 0;
		return;
	}

	description = Utils::copyDynamicString(descr);
	this->year = year;
	this->power = power;
}

Vehicle::Vehicle(const Vehicle& other):registration(other.registration)
{
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
		registration = other.registration;
	}

	return *this;
}

Vehicle::Vehicle(Vehicle&& other)noexcept :registration(std::move(other.registration))
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
		registration=std::move(other.registration);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	free();
}

unsigned int Vehicle::getYear() const
{
	return year;
}

unsigned int Vehicle::getPower() const
{
	return power;
}

const Registration& Vehicle::getRegistration() const
{
	return registration;
}

bool Vehicle::isValid() const
{
	return isValidVehicle;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
	if (!vehicle.isValid()) {
		return os << "Invalid vehicle";
	}

	os << vehicle.registration << " " << vehicle.description << " " << vehicle.year << " " << vehicle.power << " ";
	return os;
}

bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
	return lhs.getYear() == rhs.getYear() &&
		lhs.getPower() == rhs.getPower();
}

std::strong_ordering operator<=>(const Vehicle& lhs, const Vehicle& rhs)
{
	auto cmp = lhs.getYear() <=> rhs.getYear();
	if (cmp == 0) {
		cmp = lhs.getPower() <=> rhs.getPower();
	}

	return cmp;
}
