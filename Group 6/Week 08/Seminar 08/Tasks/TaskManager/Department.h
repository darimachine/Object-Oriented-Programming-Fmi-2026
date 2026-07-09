#pragma once
#include <iostream>
#include "ErrorCode.h"
#include "Employee.h"
#include <compare>
class Department
{
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;
	void free();
	void copyFrom(const Department& other);
	void moveFrom(Department&& other);
	void resize();
	int getPossition(unsigned id);

public:
	Department();
	~Department();
	Department(const Department& other);
	Department& operator=(const Department& other);
	Department(Department&& other) noexcept;
	Department& operator=(Department&& other) noexcept;
	Department(const char* name,unsigned capacity);
	ErrorCode addEmployee(const Employee& e);
	ErrorCode removeEmployee(unsigned id);
	std::strong_ordering operator<=>(const Department& other) const;
	const char* getName() const;
	double averageSalary() const;
	friend std::ostream& operator<<(std::ostream& os,const Department& d);
	const Employee& operator[](const unsigned index)const;
	Employee& operator[](unsigned index);
	explicit operator bool()const;
	Department& operator()(const int p);
};
std::ostream& operator<<(std::ostream& os,const Department& d);




