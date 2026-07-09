#pragma once
#include "Vehicle.h"
#include <iostream>

class VehicleList
{
private:
	Vehicle** slots;
	int capacity;
	int count;

	void resize();
	void free();
	int findIndex(const Registration& reg);

public: 
	VehicleList(const int initialCapacity);


	VehicleList& operator+=(const Vehicle& v);
	VehicleList& operator-=(const Registration& r);

	std::strong_ordering operator<=>(const VehicleList& other)const;

	int operator()(const char* city);

	explicit operator bool() const;

	const Vehicle& operator[](int index) const;
	Vehicle& operator[](int index);

	bool isFreeSlot(int pos) const;
	bool isEmpty() const;
	int getCapacity() const { return capacity; }
	int getSize() const { return count; }
	Vehicle* find(const Registration& reg) const;

	friend std::ostream& operator<<(std::ostream& os, const VehicleList& v);
};

