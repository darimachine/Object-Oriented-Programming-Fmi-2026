#include "Vehicle.h"
#pragma warning(disable: 4996)

Registration& Vehicle::getRegistration()
{
	return number;
}

Vehicle::Vehicle(Registration _number, const char* _decs, int _year, int _power) : number(_number), yearOfProduction(_year),power(_power)
{
	description = new char[strlen(_decs) + 1];
	strcpy(description, _decs);
}


Vehicle::~Vehicle()
{
	delete[] description;
}

bool Vehicle::operator==(Vehicle& other)
{

	if (this->yearOfProduction==other.yearOfProduction)
	{
		return true;
	}
	if (this->power == other.power)
	{
		return true;
	}
	return false;
}

std::strong_ordering Vehicle::operator<=>(Vehicle& other)
{

	if (*this==other)
	{
		return std::strong_ordering::equal;
	}
	if (this->yearOfProduction > other.yearOfProduction)
	{
		return std::strong_ordering::greater;

	}
	if (this->yearOfProduction < other.yearOfProduction)
	{
		return std::strong_ordering::less;

	}
	if (this->power > other.power)
	{
		return std::strong_ordering::greater;

	}
	if (this->power < other.power)
	{
		return std::strong_ordering::less;

	}

	return std::strong_ordering::equal;
}

std::ostream& operator<<(std::ostream& os, Vehicle& v)
{
	os << "Registration number: "<<v.number<<" \n "
		<<"description:"<<v.description<<" \n"
		<<"year: "<<v.yearOfProduction<<" \n"
		<<"power: "<<v.power<<"\n";

	return os;
}
