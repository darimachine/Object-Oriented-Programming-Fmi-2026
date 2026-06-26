#pragma once
#include <compare>
#include "Employee.h"

class Department {
	char* name = nullptr;
	Employee* employees = nullptr;
	unsigned countOfEmployees = 0;
	unsigned capacity = 0;
	
	void copyFrom(const Department& other);
	void moveFrom(Department&& other) noexcept;
	void free();
	void resize();
public:
	Department();
	Department(const char* name, unsigned capacity);
	
	Department(const Department& other);
	Department& operator=(const Department& other);
	
	Department(Department&& other) noexcept;
	Department& operator=(Department&& other) noexcept;

	~Department();

	const char* getName()const;
	ErrorCode addEmployee(const Employee& other);
	ErrorCode removeEmployee(unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Department& d);
	double getAvgSalary() const;
	std::partial_ordering operator<=>(const Department& other) const;

	Employee& operator[](size_t index);
	const Employee& operator[](size_t index) const;
	operator bool() const;
	Department& operator()(unsigned percent);
};
