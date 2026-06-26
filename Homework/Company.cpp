#include "Company.h"

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (countOfDepartments < 10) {
		departments[countOfDepartments].setName(name);
		return ErrorCode::OK;
	}
	else {
		return ErrorCode::Full;
	}
}

ErrorCode Company::removeDepartment(const char* name)
{
	for (int i = 0;i < countOfDepartments;i++) {
		if (*departments[i].getName() == *name) {
			for (int j = countOfDepartments - 1;j >= i;j--) {
				departments[i] = departments[i + 1];
			}
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	for (int i = 0;i < countOfDepartments;i++) {
		if (*departments[i].getName() == *departmentName) {
			getInstance().Department::addEmployee(employee);
			return ErrorCode::OK;
		}
	}
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	for (int i = 0;i < countOfDepartments;i++) {
		if (*departments[i].getName() == *departmentName) {
			getInstance().Department::removeEmployee(id);
			return ErrorCode::OK;
		}
	}
}

bool Company::active()
{
	if (departments[0].getName() != nullptr) {
		if (departments[0].active() == 1) {
			return 1;
		}
	}
	return 0;
}

Department* Company::operator[](char* _name)
{
	for (int i = 0;i < countOfDepartments;i++) {
		if (*departments[i].getName() == *_name) {
			return &departments[i];
		}
	}
}

Department* Company::operator[](const char* _name) const
{
	for (int i = 0;i < countOfDepartments;i++) {
		if (*departments[i].getName() == *_name) {
			Department* depart = new Department(departments[i]);
			return depart;
		}
	}
}
