#include "Company.h"

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (!name || name[0] == '\0') return ErrorCode::InvalidInput;

	if (countOfDepartments == MAX_DEPARTMENTS)
		return ErrorCode::Full;
	
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (std::strcmp(departments[i].getName(), name) == 0)
		{
			return ErrorCode::Duplicate;
		}
	}

	departments[countOfDepartments++] = Department(name, INITIAL_CAPACITY);
	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
	if (!name || name[0] == '\0') return ErrorCode::InvalidInput;

	int index = -1;
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (std::strcmp(departments[i].getName(), name) == 0)
		{
			index = i;
		}
	}

	if (index == -1)
		return ErrorCode::NotFound;

	for (size_t i = index; i < countOfDepartments - 1; i++)
	{
		departments[i] = departments[i + 1];
	}

	countOfDepartments--;
	return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	Department* dept = (*this)[departmentName];
	if (!dept) return ErrorCode::NotFound;
	return dept->addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	Department* dept = (*this)[departmentName];
	if (!dept) return ErrorCode::NotFound;
	return dept->removeEmployee(id);
}

Department* Company::operator[](const char* name)
{
	if (!name || name[0] == '\0') return nullptr;

	int count = 0;
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (std::strcmp(departments[i].getName(), name) == 0)
		{
			count++;
		}
	}
	if (count == 0)
		return nullptr;

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (std::strcmp(departments[i].getName(), name) == 0)
		{
			return &departments[i];
		}
	}
}

//const Department* Company::operator[](const char* name) const
//{
//	if (!name || name[0] == '\0') return nullptr;
//
//	int count = 0;
//	for (size_t i = 0; i < countOfDepartments; i++)
//	{
//		if (std::strcmp(departments[i].getName(), name) == 0)
//		{
//			count++;
//		}
//	}
//	if (count == 0)
//		return nullptr;
//
//	for (size_t i = 0; i < countOfDepartments; i++)
//	{
//		if (std::strcmp(departments[i].getName(), name) == 0)
//		{
//			return &departments[i];
//		}
//	}
//}

Company::operator bool() const
{
	if (!departments)
	{
		return false;
	}

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		if (!departments[i])
			return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
	os << "Company: \n";
	os << "-------------------- \n";
	for (size_t i = 0; i < company.countOfDepartments; i++)
	{
		os << company.departments[i] << std::endl;
	}
	os << "-------------------- \n";

	return os;
}
