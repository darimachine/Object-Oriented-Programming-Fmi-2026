#pragma once
#include "Department.h"

class Company
{
private:
	static constexpr unsigned int MAX_SIZE_DEP = 10;
	Department departments[MAX_SIZE_DEP];
	unsigned countOfDepartments = 0;

	Company() = default;
	Company(const Company&) = delete;
	Company& operator=(const Company&) = delete;
	Company(Company&&) = delete;
	Company& operator=(Company&&) = delete;

public:

	static Company& getInstance();

	ErrorCode addDepartment(const char*);
	ErrorCode removeDepartment(const char*);
	ErrorCode addEmployeeToDepartment(const char*, const Employee&);
	ErrorCode removeEmployeeFromDepartment(const char*, unsigned);

	friend std::ostream& operator<<(std::ostream&, const Company&);

	operator bool() const;

	Department* operator[](const char*);
};


