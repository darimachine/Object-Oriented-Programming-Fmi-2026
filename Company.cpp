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
		return ErrorCode::Full;
	}


	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0) {
			return ErrorCode::Duplicate;
		}
	}

	
	departments[countOfDepartments++] = Department(name, 15);
	return ErrorCode::OK;

}

ErrorCode Company::removeDepartment(const char* name)
{
	if (name == nullptr) {
		return ErrorCode::NotFound;
	}

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(name, departments[i].getName()) == 0) {
			std::swap(departments[i], departments[countOfDepartments - 1]);
			countOfDepartments--;
			return ErrorCode::OK;
		}
	}

	return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	if (departmentName == nullptr) {
		return ErrorCode::NotFound;
	}

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0) {
			return departments[i].addEmployee(employee);
		}
	}

	return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	if (departmentName == nullptr) {
		return ErrorCode::NotFound;
	}

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0) {
			return departments[i].removeEmployee(id);
		}
	}

	return ErrorCode::NotFound;
}

Company::operator bool() const
{
	if (countOfDepartments == 0) {
		return false;
	} 

	for (size_t i = 0; i < countOfDepartments; i++) {
		if (departments[i]) {  
			return true;
		}
	}
	return false;
}

Department* Company::operator[](const char* name)
{
	if (name == nullptr) {
		return nullptr;
	}

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0) {
			return &departments[i];
		}
	}

	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
	for (size_t i = 0; i < company.countOfDepartments; i++)
	{
		os << company.departments[i];
	}

	return os;
}
