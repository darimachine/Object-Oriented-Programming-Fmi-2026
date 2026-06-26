#include "Employee.h"

unsigned Employee::idGen = 1;

Employee::Employee() : Employee("Unnamed", "Unknown", 1)
{ }

Employee::Employee(const char* name, const char* position, double salary)
{
	this->id = idGen++;
	if (!name || !position || salary <= 0 || strlen(name) > 127 || strlen(position) > 127)
	{
		std::cerr << "Invalid data was passed. Try again";
		return;
	}
	strcpy(this->name, name);
	strcpy(this->position, position);
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
	if (amount <= 0) return ErrorCode::InvalidInput;
	if (amount == this->salary) return ErrorCode::Duplicate;
	this->salary = amount;
	return ErrorCode::OK;
}

unsigned Employee::getLastId()
{
	return Employee::idGen - 1;
}

Employee& Employee::operator++()
{
	this->salary = this->salary * 1.10;
	return *this;
}

Employee Employee::operator++(int)
{
	Employee temp = *this;
	this->salary = this->salary * 1.10;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << employee.name << ' ' << employee.position << ' ' << employee.salary;
	return os;
}

bool operator<(const Employee& employee1, const Employee& employee2)
{
	if (employee1.salary < employee2.salary)
	{
		return true;
	}

	if (employee1.salary == employee2.salary)
	{
		if (employee1.id < employee2.id) return true;
	}
	return false;
}

bool operator==(const Employee& employee1, const Employee& employee2)
{
	if (employee1.salary == employee2.salary && employee1.id == employee2.id) return true;
	return false;
}

bool operator>(const Employee& employee1, const Employee& employee2)
{
	return employee2 < employee1;
}
