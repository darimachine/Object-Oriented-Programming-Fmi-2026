#pragma once
#include "Department.h"
class Company
{
private:
	const int invalidDepId = 11;
	Department departments[10];
	unsigned int countOfDepartments;
	Company(Company&&) = delete;
	Company();
	Company operator=(const Company& c) = delete;
	Company operator=(Company&& c) = delete;
	Company(const Company& c) = delete;
	static Company instance;
	unsigned int getDepartmentIdByName(const char* name);
public:

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& c);
	operator bool();
	Department* operator[](const char* _depName);

};

