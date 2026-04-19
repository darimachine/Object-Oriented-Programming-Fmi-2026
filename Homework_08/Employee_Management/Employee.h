#pragma once
#include <ostream>
#include <compare>
#include "Utils.h"

class Employee {
	static unsigned nextId;
	unsigned id;
	char name[MAX_NAME_LENGTH];
	char position[MAX_POSITION_LENGTH];
	double salary;

public:
	Employee();
	Employee(const char* name, const char* position, double salary);
	double getSalary() const;
	ErrorCode updateSalary(double amount);
	static unsigned getNextId();
	unsigned getId() const;

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
	std::strong_ordering operator<=>(const Employee& other) const;
	bool operator==(const Employee& other) const;
	Employee& operator++();
	Employee operator++(int dummy);
};
