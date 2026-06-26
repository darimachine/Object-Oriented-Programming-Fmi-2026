#pragma once
#include "Vehicle.h"
class VehicleList
{
	Vehicle** vehicleList;
public:
	VehicleList();
	VehicleList& operator+=(const VehicleList& other);
	VehicleList& operator-=(const VehicleList& other);
	std::strong_ordering operator<=>(const VehicleList& other);
	bool operator==(const VehicleList& other);
	int operator()(char* code);
	bool isActive();
	bool isFreeSlot(int pos);
	bool isEmpty();
	int capacity(); 
	int size();
	Vehicle* find(char* reg);

};

