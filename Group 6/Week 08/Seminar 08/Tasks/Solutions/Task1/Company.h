#pragma once
#include "Department.h"

class Company
{
private:
	static constexpr size_t MAX_DEPARTMENTS = 10;

	Department departments[MAX_DEPARTMENTS];
	unsigned countOfDepartments = 0;

	Company() = default;
public:
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;
	Company(Company&&) = delete;
	Company& operator=(Company&&) = delete;

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& company);
	operator bool() const;
	Department* operator[](const char* name);
	const Department* operator[](const char* name) const;
};

