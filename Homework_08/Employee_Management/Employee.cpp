#include "Employee.h"

int Employee::nextId = 0;

Employee::Employee() : id(++nextId), salary(0.0)
{
	name[0] = '\0';
	position[0] = '\0';
}

Employee::Employee(const char* name, const char* position, double salary) : id(++nextId), salary(salary)
{
	int nameLen = std::strlen(name);
	int positionLen = std::strlen(position);
}

ErrorCode Employee::updateSalary(double amount)
{
	return ErrorCode();
}

int Employee::getNextId()
{
	return 0;
}

std::strong_ordering Employee::operator<=>(const Employee& other) const
{
	return std::strong_ordering();
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	// TODO: insert return statement here
}

std::strong_ordering Employee::operator<=>(const Employee& other) const
{
	return std::strong_ordering();
}

bool Employee::operator==(const Employee& other) const
{
	return false;
}

Employee& Employee::operator++()
{
	
}

Employee Employee::operator++(int dummy)
{
	
}