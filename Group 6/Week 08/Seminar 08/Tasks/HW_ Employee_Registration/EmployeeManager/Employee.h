#pragma once
#include "ErrorCode.h"
#include <iostream>

class Employee
{
private:
	static constexpr size_t MAX_LENGTH = 127;
	static unsigned count;

	unsigned id;
	char name[MAX_LENGTH];
	char position[MAX_LENGTH];
	double salary;
	
public:
	Employee() = default;
	Employee(char* name, char* position, double salary);
	Employee(const char* name, const char* position, double salary);

	double getSalary() const; 
	const char* getName() const { return name; }
	unsigned getId() const;

	ErrorCode updateSalary(double amount);
	unsigned static getLastId();

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

	std::partial_ordering operator<=>(const Employee& other) const;
	bool operator==(const Employee& other) const;

	Employee& operator++();	
	Employee operator++(int);
};



