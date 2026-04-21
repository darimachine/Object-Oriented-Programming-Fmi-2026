#ifndef EMPLOYEE_H

#define EMPLOYEE_H

#include<cstring>
#include<ostream>
#include<compare>

#include "Utility.h"

class Employee
{
private:
	size_t m_id;
	char m_name[128];
	char m_position[128];
	double m_salary;

	static size_t EMPLOYEE_COUNT;
	friend auto operator<<(std::ostream& os, const Employee& employee) -> std::ostream&;
	friend class Department;
protected:
public:
	explicit Employee(const char* name, const char* position = "", double salary = 0.0);
	Employee();
	auto getSalary() const -> double;
	auto getId() const -> size_t; ///
	auto updateSalary(double amount) -> ErrorCode;

	static auto getLastEmployeeId() -> size_t;

	auto operator<=>(const Employee& other) const->std::partial_ordering;
	auto operator==(const Employee& other) const -> bool;
	auto operator++() -> Employee&;
	auto operator++(int) -> Employee;
};

#endif // !EMPLOYEE_H