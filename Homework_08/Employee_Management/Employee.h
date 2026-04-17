#pragma once
#include <cstring>
#include <ostream>
#include "Utils.h"

class Employee {
	static int nextId;
	unsigned id;
	char name[128];
	char position[128];
	double salary;

public:
	Employee();
	Employee(const char* name, const char* position, double salary);
	ErrorCode updateSalary(double amount);
	static int getNextId();

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
	std::strong_ordering operator<=>(const Employee& other) const;
	bool operator==(const Employee& other) const;
	Employee& operator++();
	Employee operator++(int dummy);
};
