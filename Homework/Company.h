#pragma once
#include "Department.h"
#include "Employee.h"
class Company
{
	Department departments[10];
	unsigned countOfDepartments;
	Company();
public:
	Company operator=(const Company& other) = delete;
	Company(const Company& other) = delete;
	static Company& getInstance();
	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
	bool active();
	Department* operator[](char* _name);
	Department* operator[](const char* _name) const;

};

