#pragma once
#include"Registration.h"

class Vehicle
{
private:
	Registration registration;
	char* description = nullptr;
	unsigned year = 0;
	unsigned power = 0;
	bool isValidVehicle = true;

	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other);
	void free();

public:
	Vehicle() = delete;
	Vehicle(const Registration& registration, const char* description, unsigned year, unsigned power);

	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);

	Vehicle(Vehicle&& other)noexcept;
	Vehicle& operator=(Vehicle&& other)noexcept;

	~Vehicle();

	bool isValid()const;

	unsigned getYear()const;
	unsigned getPower()const;
	const char* getRegistation()const;
	const char* getRegistationCode()const;

	void setDescription(const char* description);

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};

std::strong_ordering operator<=>(const Vehicle& lhs, const Vehicle& rhs);
bool operator==(const Vehicle& lhs, const Vehicle& rhs);
