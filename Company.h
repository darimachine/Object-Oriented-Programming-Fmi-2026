#pragma once
#include "Department.h"


class Company
{
private:
	static constexpr unsigned int MAX_SIZE_DEP = 10;
	Department departments[MAX_SIZE_DEP];
	unsigned countOfDepartments=0;

	Company() = default;
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;

public:

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
};

