#include "Company.h"

Company::Company() = default;

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* departmentName)
{
	if (departmentName == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	if (countOfDepartments + 1 > MAX_SIZE_DEPARTMENTS)
	{
		return ErrorCode::Full;
	}

	for (unsigned i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			return ErrorCode::Duplicate;
		}
	}

	departments[countOfDepartments++] = Department(departmentName);
	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* departmentName)
{
	if (departmentName == nullptr)
	{
		return ErrorCode::InvalidInput;
	}

	for (unsigned i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			for (unsigned j = i + 1; j < countOfDepartments; j++)
			{
				departments[j - 1] = departments[j];
			}
			countOfDepartments--;
			return ErrorCode::OK;
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

	for (unsigned i = 0; i < countOfDepartments; i++)
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

	for (unsigned i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			return departments[i].removeEmployee(id);
		}
	}

	return ErrorCode::NotFound;
}

void Company::printCompany()const
{
	std::println("Company:");

	if (countOfDepartments == 0)
	{
		std::println("None");
	}

	for (unsigned i = 0; i < countOfDepartments; i++)
	{
		departments[i].printDepartment();
		std::println();
	}
}
