#include "Employee.h"
#include <cstring>
#pragma warning (disable : 4996)

unsigned Employee::count = 0;

Employee::Employee(char* name, char* position, double salary)
{
	this->id = ++count;
	std::strcpy(this->name, name);
	std::strcpy(this->position, position);
	this->salary = salary;
}

Employee::Employee(const char* name, const char* position, double salary)
{
	this->id = ++count;
	std::strcpy(this->name, name);
	std::strcpy(this->position, position);
	this->salary = salary;
}

double Employee::getSalary() const
{
	return this->salary;
}

unsigned Employee::getId() const
{
	return this->id;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount < 0)
	{
		return ErrorCode::InvalidInput;
	}

	this->salary = amount;
	return ErrorCode::OK;
}

unsigned Employee::getLastId()
{
	return count;
}



bool Employee::operator==(const Employee& other) const
{
	return id == other.id;
}

Employee& Employee::operator++()
{
	salary *= 1.10;
	return *this;
}

Employee Employee::operator++(int)
{
	Employee oldEmployee = *this;
	salary *= 1.10;
	return oldEmployee;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << "[Employee #" << employee.id << "] "
		<< employee.name << " | " << employee.position
		<< " | Salary: " << employee.salary;
	return os;
}

// <=> : primary key = salary (partial_ordering), secondary = id
std::partial_ordering Employee::operator<=>(const Employee& other) const
{
	if (auto cmp = this->salary <=> other.salary; cmp != 0) return cmp;

	auto idCmp = this->id <=> other.id;

	if (idCmp < 0) return std::partial_ordering::less;
	if (idCmp > 0) return std::partial_ordering::greater;
	return std::partial_ordering::equivalent;
}

