#pragma once
#include "Registration.h"

class Vehicle
{
private:
	Registration& registrion;
	char* description;
	short year;
	short hp;

	void resize();

public:
	Vehicle() = delete;
	Vehicle(Registration& reg, const char* description, short year, short hp);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	~Vehicle();

	Registration& getRegistration() const;

	std::strong_ordering operator<=>(const Vehicle & other) const;

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
};

