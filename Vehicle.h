#pragma once
#include "Registration.h"

class Vehicle
{
private:
	Registration registration;
	char* description = nullptr;
	unsigned int year = 0;
	unsigned int power = 0;

	bool isValidVehicle = true;

	void copyFrom(const Vehicle&);
	void free();
	void moveFrom(Vehicle&&);

public:
	Vehicle(const Registration&, const char*, int, int);
	Vehicle(const Vehicle&);
	Vehicle& operator=(const Vehicle&);
	Vehicle(Vehicle&&) noexcept;
	Vehicle& operator=(Vehicle&&)noexcept;
	~Vehicle();

	unsigned int getYear()const;
	unsigned int getPower()const;
	const Registration& getRegistration() const;
	bool isValid() const;

	friend std::ostream& operator<<(std::ostream&, const Vehicle&);
};

bool operator==(const Vehicle&, const Vehicle&);
std::strong_ordering operator<=>(const Vehicle&, const Vehicle&);

