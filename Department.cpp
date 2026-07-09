#include "Department.h"

Department::Department()
{
	name[0] = '\0';
}

Department::Department(const char* name)
{
	this->setName(name);
}

void Department::setName(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	strcpy(this->name, name);
}

const char* Department::getName()const
{
	return name;
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (countOfEmployees + 1 > this->getMaxEmployees())
	{
		return ErrorCode::Full;
	}

	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == employee.getId())
		{
			return ErrorCode::Duplicate;
		}
	}

	employees[countOfEmployees++] = employee;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id)
		{
			for (unsigned j = i + 1; j < countOfEmployees; j++)
			{
				employees[j - 1] = employees[j];
			}
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}

	return ErrorCode::NotFound;
}

unsigned Department::getMaxEmployees()
{
	return MAX_SIZE_EMPLOYEES;
}

void Department::printDepartment()const
{
	std::println("Department name:{}", name);
	
	if (countOfEmployees == 0)
	{
		std::println("None");
	}
	
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		employees[i].printEmployee();
	}
}
