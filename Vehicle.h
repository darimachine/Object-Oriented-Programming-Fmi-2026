#pragma once
#include "Registration.h"

class Vehicle {
	Registration r;
	char* descr = nullptr;
	unsigned year;
	unsigned horsepower;
	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other)  noexcept;
	void free();
public:
	Vehicle() = delete;
	Vehicle(const Registration& r, const char* descr, unsigned year, unsigned horsepower);
	Vehicle(const Vehicle& v);
	Vehicle& operator=(const Vehicle& v);
	Vehicle(Vehicle&& v) noexcept;
	Vehicle& operator=(Vehicle&& v) noexcept;
	~Vehicle();

	const Registration& getReg() const;
	unsigned getYear() const;
	unsigned getHorsepower() const;

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);

};
bool operator==(const Vehicle& lhs, const Vehicle& rhs);
bool operator!=(const Vehicle& lhs, const Vehicle& rhs);
std::strong_ordering operator<=>(const Vehicle& lhs, const Vehicle& rhs);