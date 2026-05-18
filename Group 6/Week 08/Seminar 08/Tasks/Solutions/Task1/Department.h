#pragma once
#include "Employee.h"
class Department
{
private:
	char* name = nullptr;
	Employee* employees = nullptr;
	unsigned countOfEmployees = 0;
	unsigned capacity = 8;

	void free();
	void copyFrom(const Department& other);
	void moveFrom(Department&& other) noexcept;
	void resize(unsigned newCap);

public:
	Department();
	Department(const char* name, unsigned capacity);
	Department(const Department& other);
	Department& operator=(const Department& other);
	Department(Department&& other) noexcept;
	Department& operator=(Department&& other) noexcept;
	~Department();
	
	ErrorCode addEmployee(const Employee& employee);
	ErrorCode removeEmployee(unsigned id);
	double getAverageSalary() const;
	const char* getName() const;

	friend std::ostream& operator<<(std::ostream& os, const Department& department);
	friend bool operator<(const Department& dep1, const Department& dep2);
	friend bool operator==(const Department& dep1, const Department& dep2);
	friend bool operator>(const Department& dep1, const Department& dep2);
	Employee& operator[](size_t index);
	const Employee& operator[](size_t index) const;
	operator bool() const;
	Department& operator()(double percent);
};

