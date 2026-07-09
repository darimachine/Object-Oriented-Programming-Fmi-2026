
#pragma once

#include "Employee.h"
class Department
{
private:
	char* name;
	Employee* employees;
	unsigned countOfEmployees;
	unsigned capacity;

	void copyForm(const Department& other);
	void free();
	ErrorCode resize(unsigned newCapacity);
	double averageSalary() const;

public:
	
	Department();
	Department(const char* name, unsigned capacity);

	Department(const Department& other);
	Department& operator=(const Department& other);

	Department(Department& other) noexcept;
	Department& operator=(Department&& other) noexcept;

	~Department();

	char* getName() const;
	unsigned getCountOfEmployees() const;
	unsigned getCapacity() const;


	ErrorCode addEmployee(const Employee& newEmployee);
	ErrorCode removeEmployee(unsigned id);
	Employee& operator[](unsigned index);
	const Employee& operator[](unsigned index) const;

	explicit operator bool() const;

	Department& operator()(double percent);

	friend std::ostream& operator<<(std::ostream& os, const Department& department);
	friend bool operator<(const Department& d1, const Department& d2);
	friend bool operator>(const Department& d1, const Department& d2);
	friend bool operator<=(const Department& d1, const Department& d2);
	friend bool operator>=(const Department& d1, const Department& d2);
	friend bool operator==(const Department& d1, const Department& d2);
	friend bool operator!=(const Department& d1, const Department& d2);
};

