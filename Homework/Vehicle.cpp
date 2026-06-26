#include "Vehicle.h"

Vehicle::Vehicle()
{
	number = nullptr;

}

Vehicle::Vehicle(char* _number, char* _description, char _year[4], unsigned int _horsePower)
{
	Registration(_number);
	description = new char[strlen(_description)](*_description);
	for (int i = 0;i < 4;i++) {
		year[i] = _year[i];
	}
	horsePower = _horsePower;
}

void Vehicle::print()
{
	number.print();
	std::cout << std::endl << description<< std::endl;
	for (int i = 0;i < 4;i++) {
		std::cout << year[i];
	}
	std::cout << std::endl << horsePower;
}

bool Vehicle::operator==(const Vehicle& other)
{
	for (int i = 0;i < 4;i++) {
		if (year[i] > other.year[i]) {
			return true;
		}
	}
	return false;
}

std::strong_ordering Vehicle::operator<=>(const Vehicle other)
{
	std::strong_ordering cmp = year <=> other.year;
	if (cmp == 0) {
		cmp = horsePower <=> other.horsePower;
	}
	return cmp;
}



