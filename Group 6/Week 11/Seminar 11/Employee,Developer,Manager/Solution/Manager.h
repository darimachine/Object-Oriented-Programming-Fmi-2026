#pragma once
#include "Employee.h"
class Manager : public Employee
{
	string department;
	vector<string>  subordinates;

public:
	Manager(const string& name, const string& email, double salary, const string& department);

	void addSubordinate(const string& name);
	int getTeamSize() const;
	void print() const;
};

