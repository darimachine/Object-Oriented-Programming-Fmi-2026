#ifndef VEHICLE_H

#define VEHICLE_H

#include<cstring>
#include<ostream>
#include<compare>

#include "Registration.h"

class Vehicle
{
private:
	Registration m_registration;
	char* m_description;
	unsigned int m_yearOfProduction;
	unsigned int m_engineHorsePower;

	friend auto operator<<(std::ostream& os, const Vehicle& vehicle) -> std::ostream&;

	void _free();
	void _copy(const Vehicle& from);
	void _move(Vehicle&& from);

	friend class VehicleList;

protected:
public:
	explicit Vehicle(const Registration& registration, const char* description, unsigned int yearOfProduction, unsigned int engineHorsePower);
	~Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	auto operator=(const Vehicle& other) -> Vehicle&;
	auto operator=(Vehicle&& other) noexcept -> Vehicle&;

	auto operator<=>(const Vehicle& other) const->std::partial_ordering;
	auto operator==(const Vehicle& other) const->bool;

};

#endif // !VEHICLE_H



