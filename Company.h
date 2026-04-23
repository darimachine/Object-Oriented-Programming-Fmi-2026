#pragma once
#include "Department.h"

class Company
{
private:

	static int constexpr MAX_SIZE_DEPARTMENTS = 10;
	Department departments[MAX_SIZE_DEPARTMENTS];
	unsigned countOfDepartments = 0;

	Company();

public:
	
	Company(const Company& other) = delete;

	Company& operator=(const Company& other) = delete;

	static Company& getInstance();

	ErrorCode addDepartment(const char* departmentName);
	ErrorCode removeDepartment(const char* departmentName);

	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	void printCompany()const;
};
