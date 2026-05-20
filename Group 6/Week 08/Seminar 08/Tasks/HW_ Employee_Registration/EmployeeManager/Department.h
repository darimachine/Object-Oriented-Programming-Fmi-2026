#pragma once
#include "Employee.h"
#include <iostream>

class Department
{
private:
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;

	void copyFrom(const Department& other);
	void free();
	void resize();

public:
	Department() = default;
	Department(char* name, unsigned capacity);
	Department(const char* name, unsigned capacity);

	Department(const Department& other);
	Department& operator=(const Department& other);
	~Department();

	double getAverageSalary() const;
	const char* getName() { return name; }

	ErrorCode addEmployee(const Employee& emp);
	ErrorCode removeEmployee(unsigned id);

	friend std::ostream& operator<<(std::ostream&, const Department& dep);

	std::partial_ordering operator<=>(const Department& other) const;
	bool operator==(const Department& other) const;

	Employee& operator[](unsigned index);
	const Employee& operator[](unsigned index) const;

	//available in bool context
	explicit operator bool() const { return countOfEmployees > 0; }

	Department& operator()(double percent);
};



