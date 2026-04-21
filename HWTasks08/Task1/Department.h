#ifndef DEPARTMENT_H

#define DEPARTMENT_H

#include<cstring>
#include<ostream>
#include<compare>

#include "Utility.h"
#include "Employee.h"

class Department
{
private:
	char* m_name;
	Employee* m_employees;
	size_t m_countOfEmployees;
	size_t m_capacity;

	auto _resize(size_t capacity) -> Employee*;
	auto _findById(size_t id) const -> size_t; //returns current count, if invalid
	auto _averageSalary() const -> double;

	auto _free() -> void;
	auto _copy(const Department& from) -> void;
	auto _move(Department&& from) -> void;

	friend class Company;
	friend auto operator<<(std::ostream& os, const Department& department) -> std::ostream&;

protected:
public:
	explicit Department() noexcept;
	Department(const char* name, size_t capacity);
	~Department();
	Department(const Department& other);
	auto operator=(const Department& other) -> Department&;
	Department(Department&& other) noexcept;
	auto operator=(Department&& other) noexcept -> Department&;
	auto addEmployee(const Employee& employee) -> ErrorCode;
	auto addEmployee(Employee&& employee) -> ErrorCode;
	auto removeEmployee(size_t id) -> ErrorCode;

	auto operator<=>(const Department& other) const->std::partial_ordering;
	auto operator==(const Department& other) const-> bool;
	auto operator[](size_t index) const -> const Employee&;
	auto operator[](size_t index)->Employee&;
	explicit operator bool() const; //.//
	auto operator()(unsigned int increasePercent)->Department&;
};

#endif // !DEPARTMENT_H


