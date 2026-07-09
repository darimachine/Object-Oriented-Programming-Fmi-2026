#pragma once
#include "Department.h"
#include <iostream>

class Company
{
private: 
	static constexpr unsigned MAX_DEPARTMENTS = 10;
	static const unsigned INITIAL_CAPACITY = 4;

	Department departments[MAX_DEPARTMENTS];
	unsigned countOfDepartments;

	Company() = default;

public:
	static Company& getInstance();

	Company(const Company& other) = delete;
	Company& operator=(const Company& other) = delete;
	Company(const Company&& other) = delete;
	Company& operator=(const Company&& other) = delete;

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	Department* operator[](const char* name);
	const Department* operator[](const char* name) const;

	explicit operator bool() const;

	friend std::ostream& operator<<(std::ostream& os, const Company& company);
};

