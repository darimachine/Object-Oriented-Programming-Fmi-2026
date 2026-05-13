#pragma once
#include <iostream>
#include <vector>
#include <compare>
using namespace std;

class Employee
{
	string name;
	string email;
	double salary;

public:
	Employee(const string& name, const string& email, double salary);

	const string& getName() const;
	const string& getEmail() const;
	double getSalary() const;

	void setSalary(double salary);

	partial_ordering operator<=>(const Employee& other) const;
	bool operator==(const Employee& other) const;

	friend ostream& operator<<(ostream& os, const Employee& e);
	void print() const;
};

