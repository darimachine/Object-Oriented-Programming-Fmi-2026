#include "Vehicle.h"

Vehicle::Vehicle(const Registration& reg,
    const std::string& description,
    unsigned year,
    unsigned horsePower)
    : registration(reg), description(description), 
    year(year), horsePower(horsePower)
{

}

const Registration& Vehicle::getRegistration() const
{
    return registration;
}

const std::string& Vehicle::getDescription() const
{
    return description;
}

unsigned Vehicle::getYear() const
{
    return year;
}

unsigned Vehicle::getHorsePower() const
{
    return horsePower;
}

bool Vehicle::operator==(const Vehicle& other) const
{
    return year == other.year && horsePower == other.horsePower;
}

bool Vehicle::operator!=(const Vehicle& other) const
{
    return !(*this == other);
}

bool Vehicle::operator<(const Vehicle& other) const
{
    if (year != other.year)
    {
        return year < other.year;
    }

    return horsePower < other.horsePower;
}

bool Vehicle::operator>(const Vehicle& other) const
{
    return other < *this;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
    os<< "Registration: " << vehicle.registration
        << ", Description: " << vehicle.description
        << ", Year: " << vehicle.year
        << ", HorsePower: " << vehicle.horsePower;

    return os;
}
