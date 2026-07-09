#pragma once
#include <iostream>
#include "UtilsEmployee.h"

class Employee
{
private:
	static constexpr size_t MAX_LEN = 127;
	static unsigned int countEmployee;

	unsigned int id;
	char name[MAX_LEN + 1];
	char position[MAX_LEN + 1];
	double salary = 0;

public:
	Employee();
	Employee(const char*, const char*, double);
	double getSalary() const;
	ErrorCode updateSalary(double);
	unsigned int getId() const;
	static unsigned getLastEmployeeId();

	friend std::ostream& operator<<(std::ostream&, const Employee&);
	Employee& operator++();
	Employee operator++(int dummy);
};

bool operator==(const Employee&, const Employee&);
std::strong_ordering operator <=>(const Employee&, const Employee&);