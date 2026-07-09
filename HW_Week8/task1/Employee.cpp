#include "Employee.h"
#include "Department.h"

unsigned Employee::lastId = 0;

Employee::Employee() : id(++lastId), salary(0.0)
{
	name[0] = '\0';
	position[0] = '\0';
}

Employee::Employee(const char* name, const char* position, double salary)
	: id(++lastId)
{
	if (!name || !position)
	{
		this->name[0] = '\0';
		this->position[0] = '\0';
	}
	else
	{
		if (strlen(name) >= Employee::MAX_SIZE)
		{
			this->name[0] = '\0';
		}
		else
		{
			strcpy(this->name, name);
		}

		if (strlen(position) >= Employee::MAX_SIZE)
		{
			this->position[0] = '\0';
		}
		else
		{
			strcpy(this->position, position);
		}
	}

	if (salary < 0)
	{
		this->salary = 0;
	}
	else
	{
		this->salary = salary;
	}
}

unsigned Employee::getId() const
{
	return id;
}

double Employee::getSalary() const
{
	return salary;
}

const char* Employee::getName() const
{
	return name;
}

const char* Employee::getPosition() const
{
	return position;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (salary + amount < 0)
	{
		return ErrorCode::InvalidInput;
	}
	this->salary += amount;
	return ErrorCode::OK;
}

unsigned Employee::getLastId()
{
	return lastId;
}

Employee& Employee::operator++() 
{
	const double PERCENT = 0.1;
	updateSalary(salary * PERCENT);
	return *this;
}

Employee Employee::operator++(int dummy) 
{
	const double PERCENT = 1.1;
	Employee copy = *this;
	salary *= PERCENT;
	return copy;
}

std::partial_ordering Employee::operator<=>(const Employee& other) const
{
	if (salary != other.salary)
	{
		return salary <=> other.salary;
	}
	return id <=> other.id;
}


bool Employee::operator==(const Employee& other) const
{
	bool expr = (salary == other.salary && id == other.id);
	return expr;
}

std::ostream& operator<<(std::ostream& os, const Employee& e)
{
	os << "Employee #" << e.id
		<< " " << e.name
		<< " | " << e.position
		<< " | Salary: " << e.salary;
	return os;
}
