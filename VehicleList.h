#pragma once
#include "Vehicle.h"
class VehicleList {
	Vehicle** list = nullptr;
	unsigned size = 0;
	unsigned capacity = 0;
	void resize();
	void free();
	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other) noexcept;
public:
	VehicleList() = default;
	VehicleList(unsigned capacity);
	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(VehicleList&& other)	noexcept;

	~VehicleList();

	VehicleList& operator+=(Vehicle& v);
	VehicleList& operator-=(const Vehicle& v);

	int operator()(const char* place) const;
	friend std::ostream& operator<<(std::ostream& os, const VehicleList& v);
	operator bool() const;
	Vehicle& operator[](size_t index);
	const Vehicle& operator[](size_t index) const;
	bool isFreeSlot(int pos) const;
	bool isEmpty() const;
	unsigned getCapacity() const;
	unsigned getSize() const;
	Vehicle* find(const Registration& reg);
};
bool operator==(const VehicleList& lhs, const VehicleList& rhs);
bool operator!=(const VehicleList& lhs, const VehicleList& rhs);
std::strong_ordering operator<=>(const VehicleList& lhs, const VehicleList& rhs);