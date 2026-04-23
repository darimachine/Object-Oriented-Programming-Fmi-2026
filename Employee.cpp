#include "Employee.h"
#include <cmath>

unsigned Employee::brEmployees = 0;

Employee::Employee() : id(0), salary(0)
{
	name[0] = '\0';
	position[0] = '\0';
}

Employee::Employee(const char* name, const char* position, double salary) : id(++brEmployees)
{
	this->setName(name);
	this->setPosition(position);
	this->setSalary(salary);
}

void Employee::setName(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	strcpy(this->name, name);
}

void Employee::setPosition(const char* position)
{
	if (position == nullptr)
	{
		return;
	}

	strcpy(this->position, position);
}

void Employee::setSalary(double salary)
{
	if (salary < 0)
	{
		return;
	}

	this->salary = salary;
}

double Employee::getSalary()const
{
	return salary;
}

unsigned Employee::getId()const
{
	return id;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount < 0)
	{
		return ErrorCode::InvalidInput;
	}

	if (std::abs(salary - amount) < EPSILON)
	{
		return ErrorCode::Duplicate;
	}

	salary = amount;
	return ErrorCode::OK;
}

unsigned Employee::getIdLastEmployee()
{
	return brEmployees;
}

void Employee::printEmployee()const
{
	std::println("Name:{},Position:{},Id:{},Salary:{}", name, position, id, salary);
}
