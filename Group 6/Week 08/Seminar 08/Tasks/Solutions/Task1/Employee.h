#pragma once
#include "Utils.h"
#include <iostream>

class Employee
{
private:
	static constexpr size_t MAX_LEN = 128;
	static unsigned idGen;

	unsigned id;
	char name[MAX_LEN];
	char position[MAX_LEN];
	double salary;

public:
	Employee();
	Employee(const char* name, const char* position, double salary);

	double getSalary() const;
	unsigned getId() const;
	ErrorCode updateSalary(double amount);
	static unsigned getLastId();

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
	friend bool operator<(const Employee& employee1, const Employee& employee2);
	friend bool operator==(const Employee& employee1, const Employee& employee2);
	friend bool operator>(const Employee& employee1, const Employee& employee2);
	Employee& operator++();
	Employee operator++(int);
};

