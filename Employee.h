#pragma once
#include "ErrorCode.h"
#include <ostream>
class Employee
{
private:
	unsigned id;
	char name[128];
	char position[128];
	double salary;

	static unsigned nextId;
	static unsigned lastInitializeId;

	void copyText(char* dest, const char* src, std::size_t maxLen);
	

public:
	Employee();
	Employee(const char* name, const char* position, double salary);

	unsigned getId()const;
	const char* getName() const;
	const char* getPosition() const;
	double getsalary() const;

	ErrorCode updateSalary(double amount);

	static unsigned lastIdPerson();

	Employee& operator++();
	Employee operator++(int);

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

	friend bool operator<(const Employee& e1, const Employee& e2);
	friend bool operator>(const Employee& e1, const Employee& e2);
	friend bool operator<=(const Employee& e1, const Employee& e2);
	friend bool operator>=(const Employee& e1, const Employee& e2);
	friend bool operator==(const Employee& e1, const Employee& e2);
	friend bool operator!=(const Employee& e1, const Employee& e2);

};

