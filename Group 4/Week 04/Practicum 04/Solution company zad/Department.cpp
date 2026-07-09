#include "Department.h"
unsigned int Department::countOfEmployees = 0;
ErrorCode Department::setName(char const _name[128])
{
	if (strlen(_name) == 0)
	{
		strcpy(name, _DEFAULT_NAME);
		return ErrorCode::InvalidInput;
	}
	strcpy(name, _name);

	return ErrorCode::OK;
}

bool Department::checkIfEmployeeIsInDepartment(const unsigned int id) const
{
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId()==id)
		{
			return true;
		}
	}
	return false;
}

void Department::getName(char _name[128])
{
	strcpy(_name, name);
}

Department::Department()
{
	strcpy(name, _DEFAULT_NAME);
	
}
Department::Department(char const _name[128], Employee _employees[EMPLOYEES_MAX_COUNT], unsigned int const _countOfEmployees)

{
	Util::CheckErrorCode(setName(_name));
	for (size_t i = 0; i < _countOfEmployees; i++)
	{
		Util::CheckErrorCode(addEmployee(_employees[i]));
	}
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	bool employeeIsInDepartment = checkIfEmployeeIsInDepartment(employee.getId());
	if (employeeIsInDepartment)
	{
		return ErrorCode::Duplicate;
	}
	if (countOfEmployees>= EMPLOYEES_MAX_COUNT)
	{
		return ErrorCode::DepartmentFull;
	}
	char _tempName[128];
	char _tempPosition[128];
	employee.getName(_tempName);
	employee.getPosition(_tempPosition);
	employees[countOfEmployees] = employee;
	countOfEmployees++;

	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	bool employeeIsInDepartment = checkIfEmployeeIsInDepartment(id);
	if (!employeeIsInDepartment)
	{
		return ErrorCode::InvalidInput;
	}
	Employee lastEmployee = employees[getMaxEmployees()-1];
	Employee temp;
	Employee currentEmp = employees[id];
	temp = lastEmployee;
	lastEmployee = currentEmp;
	currentEmp = temp;
	countOfEmployees--;
	return ErrorCode::OK;
}

unsigned int Department::getMaxEmployees()
{
	return countOfEmployees;
}


Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		strcpy(name, other.name);
		countOfEmployees = other.countOfEmployees;
		for (size_t i = 0; i < countOfEmployees; ++i)
		{
			employees[i] = other.employees[i];
		}
	}
	return *this;
}