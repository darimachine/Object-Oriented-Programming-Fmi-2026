#pragma once
#include "Employee.h"
class Developer : public Employee
{
	string language;
	vector<string> technologies;

public:
	Developer(const string& name, const string& email, double salary, const string& language);

	void addTechnology(const string& tech);
	bool hasTechnology(const string& tech) const;

	void print() const;

	friend ostream& operator<<(ostream& os, const Developer& d);
};

