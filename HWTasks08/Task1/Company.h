#ifndef COMPANY_H

#define COMPANY_H

#include<cstring>
#include<ostream>
#include<compare>

#include "Utility.h"
#include "Department.h"

class Company
{
private:

	Department departments[10];
	size_t countOfDepartments;

	explicit Company() = default;
	~Company() = default;

	auto _findByName(const char* name) -> size_t; //returns current count, if invalid

	friend auto operator<<(std::ostream& os, const Company& company) -> std::ostream&;

protected:
public:
	static auto instance() -> Company&;

	auto addDepartment(const char* name) -> ErrorCode;
	auto removeDepartment(const char* name) -> ErrorCode;
	auto addEmployeeToDepartment(const char* departmentName, const Employee& employee) -> ErrorCode;
	auto removeEmployeeFromDepartment(const char* departmentName, size_t id) -> ErrorCode;

	explicit operator bool() const; //.//

	auto operator[](const char* name)->Department*;
};

#endif // !COMPANY_H