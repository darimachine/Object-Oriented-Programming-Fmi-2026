#include "Company.h"
#include<print>

Company& Company::getInstance()
{
	static Company company;
	return company;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (name == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (strcmp(departments[i].getName(), name) == 0)
		{
			return ErrorCode::Duplicate;
		}
	}

	Department department(name, DEFAULT_CAPACITY);
	departments[countOfDepartments++] = department;
	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
	if (name == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (strcmp(departments[i].getName(), name) == 0)
		{
			size_t pos = i;
			for (size_t j = pos;j < countOfDepartments - 1;j++)
			{
				departments[j] = departments[j + 1];
				countOfDepartments--;
				return ErrorCode::OK;
			}
		}
	}

	return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	if (departmentName == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			return departments[i].addEmployee(employee);
		}
	}
	return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	if (departmentName == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			return departments[i].removeEmployee(id);
		}
	}
	return ErrorCode::NotFound;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
	for (size_t i = 0;i < company.countOfDepartments;i++)
	{
		os << company.departments[i];
	}
	return os;
}

Company::operator bool()
{
	if (countOfDepartments == 0)
	{
		return false;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (departments[i])
		{
			return true;
		}
	}
	return false;
}

Department* Company::operator[](const char* name)
{
	if (name == nullptr)
	{
		return nullptr;
	}

	for (size_t i = 0;i < countOfDepartments;i++)
	{
		if (strcmp(departments[i].getName(), name) == 0)
		{
			return &departments[i];
		}
	}

	return nullptr;
}