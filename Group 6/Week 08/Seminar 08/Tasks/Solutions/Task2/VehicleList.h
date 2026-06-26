#pragma once
#include "Vehicle.h"
class VehicleList
{
private:
	Vehicle** vehicles = nullptr;
	size_t vehicleCount = 0;
	size_t vehicleCapacity = 8;

	void free();
	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other) noexcept;
	void resize(size_t newCap);
public:
	VehicleList();
	VehicleList(size_t capacity);
	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(VehicleList&& other) noexcept;
	~VehicleList();

	bool isFreeSlot(size_t pos) const;
	bool isEmpty() const;
	size_t capacity() const;
	size_t size() const;
	Vehicle* find(const Registration& reg) const;

	friend void operator+=(VehicleList& vehicleList, const Vehicle& vehicle);
	friend void operator-=(VehicleList& vehicleList, const Registration& regNumber);
	friend std::ostream& operator<<(std::ostream& os, const VehicleList& vl);
	friend bool operator<(const VehicleList& vl1, const VehicleList& vl2);
	friend bool operator==(const VehicleList& vl1, const VehicleList& vl2);
	friend bool operator>(const VehicleList& vl1, const VehicleList& vl2);
	size_t operator()(const char* cityCode) const;
	operator bool() const;
	Vehicle* operator[](size_t index);
	const Vehicle* operator[](size_t index) const;
};

