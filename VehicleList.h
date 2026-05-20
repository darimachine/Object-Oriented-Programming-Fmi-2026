#pragma once
#include "Vehicle.h"

class VehicleList
{
private:
	Vehicle** list = { nullptr };
	size_t countOfVehicles = 0;
	size_t capacity = 15;

	void resize(size_t);
	void copyFrom(const VehicleList&);
	void moveFrom(VehicleList&&);
	void free();

public:
	explicit VehicleList(size_t capacity);
	VehicleList(const VehicleList&);
	VehicleList& operator=(const VehicleList&);
	VehicleList(VehicleList&&) noexcept;
	VehicleList& operator=(VehicleList&&) noexcept;
	~VehicleList();

	size_t getCount()const;
	size_t getCapacity()const;
	const Vehicle* const* getList() const;

	VehicleList& operator+=(const Vehicle&);
	VehicleList& operator-=(const Registration&);
	friend std::ostream& operator<<(std::ostream&, const VehicleList&);

	size_t operator()(const char*) const;
	operator bool() const;

	const Vehicle& operator[](size_t index)const;
	Vehicle& operator[](size_t index);

	bool isFreeSlot(size_t pos);
	bool isEmpty();
	Vehicle* find(const Registration&) const;
};

bool operator== (const VehicleList&, const VehicleList&);
std::strong_ordering operator<=>(const VehicleList&, const VehicleList&);

