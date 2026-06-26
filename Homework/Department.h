#pragma once
#include "Employee.h"
#include <compare>
#include <iostream>
class Department
{
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;
public:
	Department();
	Department(char* _name, unsigned _capacity);
	Department( const Department& other);
	Department operator=(const Department& other);
	void setName(const char*);
	char* getName();
	void copyFrom(const Department other);
	void free();
	void resize();
	char* getName() const;
	ErrorCode addEmployee(Employee other);
	ErrorCode removeEmployee(unsigned int id);
	void print();
	std::strong_ordering operator<=>(const Department& other);
	Employee operator[](int index);
	Employee operator[](int index) const;
	bool active();
	Department& operator()(double percent);
	double averageSalary() const;
	~Department();



};

