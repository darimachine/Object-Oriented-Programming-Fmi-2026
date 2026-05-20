#pragma once
#include "Registration.h"
#include <ostream>
#include <compare>

class Vehicle {
	Registration registration;
	char* description = nullptr;
	int year;
	int power;

	void free();
	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other) noexcept;

public:
	~Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(const Vehicle& other);
	Vehicle& operator=(Vehicle&& other) noexcept;

	Vehicle(const Registration& registration,const char* description, int year, int power);
	friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
	std::strong_ordering operator <=>(const Vehicle& other) const;
	bool operator==(const Vehicle& other) const;

	const Registration& getRegistration() const;
};
