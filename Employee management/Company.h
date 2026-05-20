#pragma once
#include "Department.h"
const int DSIZE = 10;
class Company
{
private:
	static Company* instance;
	Department departments[DSIZE];
	unsigned countOfDepartments;
	Company();
public:
	static Company& getInstance();
	ErrorCode addDepartment(const char* n);
	ErrorCode removeDepartment(const char* n);
	ErrorCode addEmployeeToDepartment(const char* d, const Employee& e);
	ErrorCode removeEmployeeFromDepartment(const char* d, unsigned i);
	friend std::ostream& operator<<(std::ostream& out, Company& C);
	explicit operator bool() const;
	Department* operator[](const char* d);
	Company(const Company& other) = delete;
	Company operator=(const Company& C) = delete;

};

