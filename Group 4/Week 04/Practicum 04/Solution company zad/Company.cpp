#include "Company.h"
#include <print>
using std::println;
using std::strcmp;
Company::Company() : countOfDepartments(0)
{
println("creating company");
}

Department Company::getDepartmentByName(const char* name)
{

	for (size_t i = 0; i < countOfDepartments; i++)
	{
		char _name[128];
		departments[i].getName(_name);
		if (strcmp(name, _name) == 0)
		{
			return departments[i];
		}
	}
	//няма да стигне до тук, защото сме проверили, 
	// че съществува департмента преди да извикаме тази функция : )
	return Department();
}

bool Company::departmentWithThisNameExists(const char* name)
{
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		char _name[128];
		departments[i].getName(_name);
		if (strcmp(name,_name)==0)
		{
			return true;
		}
	}
	return false;
}

Company& Company::getInstance()
{
	static Company instance; 
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (countOfDepartments>=_MAX_DEPARTMENTS)
	{
		return ErrorCode::CompanyDepartmentsFull;
	}
	bool checkIfDepartmentWithThisNameExists =departmentWithThisNameExists(name);
	if (checkIfDepartmentWithThisNameExists==true)
	{
		return ErrorCode::CompanyDepartmentsFull;
	}
	Util::CheckErrorCode(departments[countOfDepartments].setName(name));
	countOfDepartments++;
	return ErrorCode::OK;
}


ErrorCode Company::removeDepartment(const char* name)
{
	if (countOfDepartments == 0)
	{
		return ErrorCode::InvalidInput;
	}
	bool checkIfDepartmentWithThisNameExists = departmentWithThisNameExists(name);
	if (!checkIfDepartmentWithThisNameExists) 
	{
		return ErrorCode::InvalidInput;
	}
	size_t indexToRemove = 0;
	for (size_t i = 0; i < countOfDepartments; i++)
	{
		char _name[128];
		departments[i].getName(_name);
		if (strcmp(name, _name) == 0)
		{
			indexToRemove = i;
			break;
		}
	}
	if (countOfDepartments > 1 && indexToRemove < countOfDepartments - 1)
	{
		departments[indexToRemove] = departments[countOfDepartments - 1];
	}
	countOfDepartments--;
	return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	bool checkIfDepartmentWithThisNameExists = departmentWithThisNameExists(departmentName);
	if (checkIfDepartmentWithThisNameExists == true)
	{
		return ErrorCode::InvalidInput;
	}

	Department dep = getDepartmentByName(departmentName);
	Util::CheckErrorCode(dep.addEmployee(employee));

	return ErrorCode::OK;
}


ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	bool checkIfDepartmentWithThisNameExists = departmentWithThisNameExists(departmentName);
	if (checkIfDepartmentWithThisNameExists == true)
	{
		return ErrorCode::InvalidInput;
	}
	Department dep = getDepartmentByName(departmentName);
	Util::CheckErrorCode(dep.removeEmployee(id));

	return ErrorCode::OK;
}


