#pragma once
#include "Registration.h"
class Vehicle
{
private:
	Registration number;
	char* description;
	int yearOfProduction;
	int power;

	Vehicle() = delete;

public:
	Registration& getRegistration();
	Vehicle(Registration _number, const char* _decs, int _year, int _power);
	~Vehicle();
	friend std::ostream& operator<<(std::ostream& os, Vehicle& v);

	bool operator==(Vehicle& other);
	std::strong_ordering operator<=>(Vehicle& other);


};

