#pragma once

enum class ErrorCode {
	OK,
	NotFound,
	Duplicate,
	InvalidInput
};

class Employee
{
private:
	static constexpr size_t MAX_LEN = 127;
	unsigned int id;
	char name[MAX_LEN+1];
	char position[MAX_LEN+1];
	double salary=0;
	static unsigned int countEmployee;

public:
	Employee();
	Employee(const char*, const char*, double);
	double getSalary() const;
	ErrorCode updateSalary(double amount);
	unsigned int getId() const;
	static unsigned getLastEmployeeId();
};

