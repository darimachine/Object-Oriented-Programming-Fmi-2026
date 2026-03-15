#include <iostream>
#include "Company.h"

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name) {

	if (name == nullptr) {
		return ErrorCode::NotFound;
	}

	if (countOfDepartments >= MAX_SIZE_DEP) {
		return ErrorCode::InvalidInput;
	}
		

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0) {
			return ErrorCode::Duplicate;
		}
	}

	Department newDepartment(name);
	departments[countOfDepartments++] = newDepartment;
	return ErrorCode::OK;
	
}

ErrorCode Company::removeDepartment(const char* name) {

	if (name == nullptr) {
		return ErrorCode::NotFound;
	}

	size_t index = 0;
	bool found = false;

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0) {
			index = i;
			found = true;
			break;
		}
		
	}

	if (!found)
		return ErrorCode::NotFound;

	for (size_t i = index; i < countOfDepartments-1; i++)
	{
		departments[i] = departments[i + 1];
	}

	countOfDepartments--;
	return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee) {
	if (departmentName == nullptr) {
		return ErrorCode::NotFound;
	}

	bool found = false;
	size_t index = 0;
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0) {
			index = i;
			found = true;
			break;
		}
	}

	if (!found)
		return ErrorCode::NotFound;

	return departments[index].addEmployee(employee);

}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id) {

	if (departmentName == nullptr) {
		return ErrorCode::NotFound;
	}
	size_t index = 0;

	bool found = false;
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0) {
			index = i;
			found = true;
			break;
		}
	}

	if (!found)
		return ErrorCode::NotFound;

	return departments[index].removeEmployee(id);

}