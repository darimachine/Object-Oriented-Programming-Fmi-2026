#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include<cstring>

unsigned Employee::countOfEmployees = 0;

Employee::Employee() :id(0), salary(0)
{
	name[0] = '\0';
	position[0] = '\0';
}

Employee::Employee(const char* name, const char* position, double salary):id(++countOfEmployees)
{
	setName(name);
	setPosition(position);
	setSalary(salary);
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

ErrorCode Employee::updateSalary(double update)
{
	if (salary + update < 0)
	{
		return ErrorCode::InvalidInput;
	}

	salary += update;
	return ErrorCode::OK;
}

unsigned Employee::getId()const
{
	return id;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << employee.name << " " << employee.position
		<< " " << employee.salary << '\n';
	return os;
}

std::strong_ordering operator<=>(const Employee& lhs, const Employee& rhs)
{
	auto cmp = lhs.getSalary() <=> rhs.getSalary();

	if (cmp != 0)
	{
		if (cmp < 0)
		{
			return std::strong_ordering::less;
		}
		else
		{
			return std::strong_ordering::greater;
		}
	}

	return lhs.getId() <=> rhs.getId();

}

bool operator==(const Employee& lhs, const Employee& rhs)
{
	return isEqualSalary(lhs.getSalary(), rhs.getSalary()) && lhs.getId() == rhs.getId();
}

const Employee& Employee::operator++()
{
	salary += (PERCENTAGE * salary);
	return *this;
}

const Employee Employee::operator++(int dummy)
{
	Employee temp(*this);
	salary += (PERCENTAGE * salary);
	return temp;
}