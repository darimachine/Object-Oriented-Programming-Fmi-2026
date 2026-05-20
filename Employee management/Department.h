#pragma once
#include "Employee.h"
class Department
{
private:
	char* name=nullptr;
	Employee* employees=nullptr;
	unsigned countOfEmployees;
	unsigned capacity;
public:
	Department();
	Department(const char* n,unsigned c);
	ErrorCode addEmployee(Employee e);
	char* getName();
	ErrorCode removeEmployee(unsigned i);
	friend std::ostream& operator<<(std::ostream& out, const Department& E);
	Employee& operator[](int index);
	const Employee& operator[](int index) const;
	explicit operator bool() const;
	Department& operator()(int parcent);
	friend bool operator<(const Department& D1, const Department& D2);
	friend bool operator>(const Department& D1, const Department& D2);
	friend bool operator==(const Department& D1, const Department& D2);
};


