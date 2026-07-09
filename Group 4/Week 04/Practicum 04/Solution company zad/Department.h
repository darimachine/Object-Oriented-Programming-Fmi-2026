#pragma once
#include "Employee.h"
class Department
{
	const char _DEFAULT_NAME[128] = "Default_name";
	static const int EMPLOYEES_MAX_COUNT = 15;
	char name[128];
	Employee employees[EMPLOYEES_MAX_COUNT];
	static unsigned int countOfEmployees;
	bool checkIfEmployeeIsInDepartment(const unsigned int id) const;
public:
	ErrorCode setName(char const _name[128]);

	void getName(char name[128]);
	Department();
	Department(char const _name[128], Employee _employees[EMPLOYEES_MAX_COUNT], unsigned int const _countOfEmployees);
	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);
	static unsigned int getMaxEmployees();
	Department& operator=(const Department& other);
	

};

