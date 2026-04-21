#ifndef VEHICLE_LIST_H

#define VEHICLE_LIST_H

#include<cstring>
#include<ostream>
#include<compare>

#include "Vehicle.h"

class VehicleList
{
private:
	Vehicle** m_vehicles;
	size_t m_capacity;
	size_t m_count;

	friend auto operator<<(std::ostream& os, const VehicleList& vehicleList) -> std::ostream&;

	auto _resize(size_t capacity) -> Vehicle**;
	auto _findVehicleByRegistration(const Registration& registration) const -> size_t;

	void _free();
	void _copy(const VehicleList& from);
	void _move(VehicleList&& from);

protected:
public:
	explicit VehicleList(size_t capacity);
	~VehicleList();
	VehicleList(const VehicleList& other);
	VehicleList(VehicleList&& other) noexcept;
	auto operator=(const VehicleList& other) -> VehicleList&;
	auto operator=(VehicleList&& other) noexcept -> VehicleList&;

	auto operator+=(const Vehicle& vehicle) -> VehicleList&;
	auto operator-=(const Registration& registration) -> VehicleList&;
	auto operator()(const char* areaCode)->size_t;
	auto operator[](size_t index) const->Vehicle*;
	auto operator[](size_t index)->Vehicle*;

	auto operator<=>(const VehicleList& other) const->std::partial_ordering;
	auto operator==(const VehicleList& other) const->bool;
	explicit operator bool() const;

	auto isFreeSlot(size_t position) -> bool;
	auto isEmpty() -> bool;
	auto capacity() -> size_t;
	auto size() -> size_t;
	auto find(const Registration& registration) -> Vehicle*;
};

#endif // !VEHICLE_LIST_H



