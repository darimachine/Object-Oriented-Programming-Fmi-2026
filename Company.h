#pragma once
#include "Department.h"
class Company {
	static const int MAX_SIZE = 10;
	Department departments[MAX_SIZE];
	unsigned countOfDepartments = 0;
	Company();
	int getIndexByName(const char* name) const;
public:
	static Company& getInstance();

	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;
	Company(Company&&) = delete;
	Company& operator=(Company&&) = delete;

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName,const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& company);
	operator bool() const;
	Department* operator[](const char* name);
	const Department* operator[](const char* name) const;
};

