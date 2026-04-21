#include "Employee.h"
#pragma warning(disable : 4996)
#include "Util.h"
using std::strcpy;
using std::strlen;
ErrorCode Employee::SetName(char const _name[128])
{
	if (strlen(_name)==0)
	{
		strcpy(name, _DEFAULT_NAME);
		return ErrorCode::InvalidInput;
	}
	strcpy(name, _name);

	return ErrorCode::OK;
}
ErrorCode Employee::SetPosition(char const _position[128])
{
	if (strlen(_position) == 0)
	{
		strcpy(position, _DEFAULT_NAME);
		return ErrorCode::InvalidInput;
	}
	strcpy(position, _position);

	return ErrorCode::OK;
}
ErrorCode Employee::updateSalary(double amount)
{
	if (amount < 0)
	{
		return ErrorCode::InvalidInput;
	}
	salary = amount;
	return ErrorCode::OK;
}
Employee::Employee():id(0), salary(0)
{
	strcpy(name,_DEFAULT_NAME);
	strcpy(name, _DEFAULT_POSITION);
}

Employee::Employee(char const _name[128], char const _position[128], double const _salary):id(CounterIdEmployee++)
{
	Util::CheckErrorCode(updateSalary(_salary));
	Util::CheckErrorCode(SetName(_name));
	Util::CheckErrorCode(SetPosition(_position));
	
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::getName(char _name[128]) const
{
	strcpy(_name, name);
}

void Employee::getPosition(char _position[128]) const
{
	strcpy(_position, position);
}

unsigned int Employee::getLastEmployeeId() const
{
	return CounterIdEmployee;
}

unsigned int Employee::getId() const
{
	return id;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) // Prevent self-assignment
	{
		strcpy(name, other.name);
		strcpy(position, other.position);
		salary = other.salary;
		id = other.id;
	}
	return *this;
}
