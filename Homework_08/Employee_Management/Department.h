#pragma once
#include <ostream>
#include <compare>
#include "Employee.h"
#include "Utils.h"

class Department {
	char* name = nullptr;
	Employee* employees = nullptr;
	unsigned countOfEmployees = 0;
	unsigned capacity = 8;

	void resize();
	void copyFrom(const Department& other);
	void moveFrom(Department&& other);
	void free();

	friend class Company;

public:
	Department();
	~Department();
	Department(const Department& other);
	Department(Department&& other) noexcept;
	Department& operator=(const Department& other);
	Department& operator=(Department&& other) noexcept;

	Department(const char* name, unsigned capacity);
	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Department& department);
	std::strong_ordering operator<=>(const Department& other) const;
	bool operator==(const Department& other) const;
	Employee& operator[](unsigned index);
	const Employee& operator[](unsigned index) const;
	explicit operator bool() const;
	Department& operator()(double percentage);

	double getAverageSalary() const;
};