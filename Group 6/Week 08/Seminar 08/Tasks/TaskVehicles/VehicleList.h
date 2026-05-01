#pragma once
#include "Vehicle.h"
#include <iostream>
class VehicleList
{
	Vehicle** vehicles;
	unsigned currentSize = 0;
	unsigned capacity = 0;
	int contains(const Vehicle& v);
	void resize();
	void free();
	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other);
public:
	VehicleList(size_t size);
	~VehicleList();
	VehicleList(const VehicleList& other);
	VehicleList& operator+=(const Vehicle& other);
	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(const VehicleList& other);
	VehicleList& operator=(VehicleList&& other) noexcept;
	VehicleList& operator-=(const Registration& reg);
	friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
	std::strong_ordering operator<=>(const VehicleList& other) const;
	int operator()(const char* city) const;
	explicit operator bool() const;
	const Vehicle& operator[](int i) const;
	Vehicle& operator[](int i);
	bool isFreeSlot(int pos) const;
	bool isEmpty() const;
	int getCapacity() const;
	int size() const;
	Vehicle* find(const Registration& reg);
};
std::ostream& operator<<(std::ostream& os, const VehicleList& list);


