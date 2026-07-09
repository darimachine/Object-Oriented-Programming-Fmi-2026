#pragma once
#include "Employee.h"

class Department
{
private:

	static constexpr int MAX_SIZE_EMPLOYEES = 15;
	static constexpr int MAX_SIZE_NAME = 127;

	char name[MAX_SIZE_NAME];
	Employee employees[MAX_SIZE_EMPLOYEES];
	unsigned countOfEmployees = 0;

public:

	Department();

	Department(const char* name);

	void setName(const char* name);

	const char* getName()const;

	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);

	static unsigned getMaxEmployees();

	void printDepartment()const;
};
