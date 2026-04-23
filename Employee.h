#pragma once
#include"Utils.h"
#include<fstream>
#include<compare>

class Employee
{
private:
	static constexpr size_t MAX_LEN = 128;
	static constexpr double PERCENTAGE = 0.10;
	static unsigned countOfEmployees;

	unsigned id = 0;
	char name[MAX_LEN];
	char position[MAX_LEN];
	double salary = 0;

public:
	Employee();
	Employee(const char* name, const char* position, double salary);

	void setName(const char* name);
	void setPosition(const char* position);
	void setSalary(double salary);

	double getSalary()const;
	ErrorCode updateSalary(double update);

	unsigned getId()const;

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

	const Employee& operator++();
	const Employee operator++(int dummy);
};

bool operator==(const Employee& lhs, const Employee& rhs);
std::strong_ordering operator<=>(const Employee& lhs, const Employee& rhs);
