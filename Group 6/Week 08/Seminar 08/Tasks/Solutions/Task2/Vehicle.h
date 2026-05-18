#pragma once
#include "Registration.h"
class Vehicle
{
private:
	Registration regNumber = nullptr;
	char* description = nullptr;
	int makeYear = 2000;
	int horsePower = 100;

	void free();
	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other) noexcept;
public:
	Vehicle() = delete;
	Vehicle(const Registration& registration, const char* description, int makeYear, int horsePower);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(Vehicle&& other) noexcept;
	~Vehicle();

	const char* getReg() const;

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
	friend bool operator<(const Vehicle& vehicle1, const Vehicle& vehicle2);
	friend bool operator==(const Vehicle& vehicle1, const Vehicle& vehicle2);
	friend bool operator>(const Vehicle& vehicle1, const Vehicle& vehicle2);
};

