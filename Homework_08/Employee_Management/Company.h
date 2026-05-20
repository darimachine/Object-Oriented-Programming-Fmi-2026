#pragma once
#include "Utils.h"
#include "Department.h"

class Company {
	Department departments[MAX_DEPARTMENTS];
	unsigned countOfDepartments;
	Company();

public:
	static Company& getInstance();
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;
	Company(Company&&) = delete;
	Company& operator=(Company&&) = delete;

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& company);
	Department* operator[](const char* name);
	const Department* operator[](const char* name) const;
	explicit operator bool() const;
};