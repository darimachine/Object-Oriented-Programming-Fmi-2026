#pragma once
#include <iostream>
#include "ErrorCode.h"
#include "Department.h"

class Company
{
private:
	Department departments[10];
	unsigned countOfDepartments = 0;
	Company() = default;
	int getDepartmentIndex(const char* name);

public:
	static Company& getInstance();
	Company(const Company& other) = delete;
	Company(Company&& other) = delete;
	Company& operator=(const Company& other) = delete;
	Company& operator=(Company&& other) = delete;
	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
	friend std::ostream& operator<<(std::ostream& os,const Company& c);
	Department* operator[](const char* name);
	explicit operator bool() const;
};
std::ostream& operator<<(std::ostream& os,const Company& c);

