#pragma once
#include "Employee.h"


class Department
{
private:
	static constexpr size_t MAX_LEN = 127;
	static constexpr size_t MAX_SIZE = 15;
	char name[MAX_LEN + 1]="";
	Employee employees[MAX_SIZE];
	unsigned countOfEmployees=0;

public:
	Department()=default;
	Department(const char*);
	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);
	static unsigned getMaxEmployees();
	const char* getName()const;
	
};

