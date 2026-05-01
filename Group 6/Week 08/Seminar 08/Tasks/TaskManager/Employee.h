#pragma once
#include <iostream>
#include "ErrorCode.h"

class Employee
{
	static unsigned id;
	unsigned currentId = 0;
	char name[128] = {};
	char possition[128] = {};
	double salary = 0;;

public:
	Employee();
	Employee(const char* name,const char* possition, double salary);
	double getSalary() const;
	ErrorCode updateSalary(double amount);
	ErrorCode updateSalary(int percentage);
	static unsigned getLastId();
	unsigned getId() const;
	friend std::ostream& operator<<(std::ostream& os, Employee& obj);
	std::strong_ordering operator<=>(const Employee& other) const;
	Employee& operator++();
	Employee operator++(int);
};
std::ostream& operator<<(std::ostream& os, Employee& obj);
