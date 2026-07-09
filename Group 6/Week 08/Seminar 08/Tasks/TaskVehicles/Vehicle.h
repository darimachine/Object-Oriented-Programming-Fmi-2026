#pragma once
#include "Registration.h"
#include <iostream>
class Vehicle
{
	Registration number;
	char* description = nullptr;
	int year = 0;
	int hp = 0;
	void free();
public:
	Vehicle() = delete;
	Vehicle(const Registration& r, const char* description, int year, int hp);
	~Vehicle();
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(Vehicle&& other) noexcept;
	const Registration& registration()const;
	friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::strong_ordering operator<=>(const Vehicle& other) const;
	bool operator==(const Vehicle& other) const;
};
std::ostream& operator<<(std::ostream& os, const Vehicle& v);
