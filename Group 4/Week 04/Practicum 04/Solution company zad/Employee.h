#pragma once
#include "Util.h"
class Employee
{
	const char _DEFAULT_NAME[128] = "Default_name";
	const char _DEFAULT_POSITION[128] = "Default_positon";
	unsigned int CounterIdEmployee=0;
	unsigned int id;
	char name[128];
	char position[128];
	double salary;
	ErrorCode SetName(char const _name[128]);
	ErrorCode SetPosition(char const _position[128]);

public:
	ErrorCode updateSalary(double amount);
	Employee();
	Employee(char const _name[128], char const _position[128], double const _salary);
	double getSalary() const;
	void getName(char _name[128]) const;
	void getPosition(char _position[128]) const;
	unsigned int getLastEmployeeId() const;
	unsigned int getId() const;
	Employee& operator=(const Employee& other);

};

