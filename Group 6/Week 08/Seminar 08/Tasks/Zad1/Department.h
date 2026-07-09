#pragma once
#include "Employee.h"
class Department
{
private:
	char* name;
	Employee* employees;
	unsigned int countOfEmployees;
	unsigned int capacity;
	void doubleCapacity();
public:
	char* getName();
	Department(const Department& other);
	Department& operator=(const Department& other);
	~Department();
	double avgSalary() const;

	Department();
	Department(const char* _name);
	ErrorCode addEmployee(const Employee& _empl);
	ErrorCode removeEmployee(const unsigned int id);


	friend std::ostream& operator<<(std::ostream& os, const Department& d);

	bool operator==(const Department& other) const;

	std::strong_ordering operator<=>(const Department& other) const;

	Employee& operator[](int id);
	Employee& operator[](int id) const;
	operator bool();
	Department& operator()(double perc);

	Department(Department&& other);
	Department& operator=(Department&& other);
};

