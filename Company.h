#pragma once
#include"Department.h"

class Company
{
private:
	static constexpr unsigned DEFAULT_CAPACITY = 16;
	static constexpr size_t DEFAULT_SIZE = 10;
	Department departments[DEFAULT_SIZE];
	unsigned countOfDepartments = 0;

	Company() = default;

public:
	Company(const Company& other) = delete;
	Company& operator=(const Company& other) = delete;
	Company(Company&& other) = delete;
	Company& operator=(Company&& other) = delete;

	static Company& getInstance();

	ErrorCode addDepartment(const char* name);
	ErrorCode removeDepartment(const char* name);
	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

	friend std::ostream& operator<<(std::ostream& os, const Company& company);

	explicit operator bool();
	Department* operator[](const char* name);
};

