#pragma once
#include "Department.h"

class Company
{
	static const int _MAX_DEPARTMENTS = 10;
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;
	Company();
	Department departments[_MAX_DEPARTMENTS];
	unsigned int countOfDepartments;

	Department getDepartmentByName(const char* name);
	bool departmentWithThisNameExists(const char* name);
public:
	static Company& getInstance();
	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

};

