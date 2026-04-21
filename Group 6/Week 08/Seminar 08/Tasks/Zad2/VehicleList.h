#pragma once
#include "Vehicle.h"
class VehicleList
{
	Vehicle** list;
	int _size;
	int _capacity;
	int getOpenSlot();
	void doubleSize();
	int getVehicleSlot(Vehicle& v);
	int getFistOpenSlot();
public:
	bool isFreeSlot(int pos);

	VehicleList() = delete;
	VehicleList(int _size);
	~VehicleList();

	Vehicle* find(Registration& reg);

	VehicleList& operator+=(Vehicle& v);
	VehicleList& operator-=(Registration& reg);
	

	friend std::ostream& operator<<(std::ostream& os, VehicleList& v);
	bool operator==(VehicleList& other);
	std::strong_ordering operator<=>(VehicleList& other);

	int operator()(const char* code);

	operator bool();

	Vehicle& operator[](int index);

	bool isEmpty();
	int capacity();
	int size();
};

