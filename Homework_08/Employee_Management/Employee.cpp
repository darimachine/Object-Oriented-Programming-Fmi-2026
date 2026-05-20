#define _CRT_SECURE_NO_WARNINGS

#include "Employee.h"
#include <cstring>
#include <cmath>
#include "Utils.h"

unsigned int Employee::nextId = 0;

Employee::Employee() : id(++nextId), salary(0.0)
{
	name[0] = '\0';
	position[0] = '\0';
}

Employee::Employee(const char* name, const char* position, double salary) : id(++nextId), salary(salary < 0 ? 0.0 : salary)
{
	if (std::strlen(name) < MAX_NAME_LENGTH) {
		std::strcpy(this->name, name);
	}
	else {
		this->name[0] = '\0';
	}

	if (std::strlen(position) < MAX_POSITION_LENGTH) {
		std::strcpy(this->position, position);
	}
	else {
		this->position[0] = '\0';
	}
}

double Employee::getSalary() const
{
	return this->salary;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount < 0) {
		return ErrorCode::InvalidInput;
	}

	this->salary = amount;
	return ErrorCode::OK;
}

unsigned Employee::getNextId()
{
	return nextId;
}

unsigned Employee::getId() const
{
	return id;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << "ID: " << employee.id << std::endl 
		<< "Name: " << employee.name << std::endl 
		<< "Position: " << employee.position << std::endl 
		<< "Salary: " << employee.salary << std::endl;

	return os;
}

std::strong_ordering Employee::operator<=>(const Employee& other) const
{
	if (std::abs(this->salary - other.salary) < EPSILON) {
		return this->id <=> other.id;
	}

	if (this->salary < other.salary) {
		return std::strong_ordering::less;
	}
	else {
		return std::strong_ordering::greater;
	}
}

bool Employee::operator==(const Employee& other) const
{
	return std::abs(this->salary - other.salary) < EPSILON && this->id == other.id;
}

Employee& Employee::operator++()
{
	this->salary *= 1.10;
	return *this;
}

Employee Employee::operator++(int dummy)
{
	Employee temp = *this;
	++(*this);
	return temp;
}