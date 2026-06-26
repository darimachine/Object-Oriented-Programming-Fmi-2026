#pragma once
#include "Registration.h"
class Vehicle
{
	Registration number;
	char* description;
	char year[4];
	unsigned int horsePower;
public:
	Vehicle();
	Vehicle(char* _number, char* _description, char _year[4], unsigned int _horsePower);
	void print();
	bool operator==(const Vehicle& other);
	std::strong_ordering operator<=>(const Vehicle other);

};

