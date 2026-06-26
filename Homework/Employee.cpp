#include "Employee.h"
unsigned int Employee::id = 0;
Employee::Employee() {
	this->id = id;
	salary = 0;
	id++;
}

Employee::Employee(char* name, char* position, double salary)
{
	if (strlen(name) < 128) {
		this->id = id;
		for (int i = 0;i < strlen(name);i++) {
			this->name[i] = name[i];
		}
	}
	if (strlen(position) < 127) {
		for (int i = 0;i < strlen(position);i++) {
			this->position[i] = position[i];
		}
	}
	this->salary = salary;
}

double Employee::getSalary() const
{
	return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount == salary) {
		return ErrorCode::Duplicate;
	}
	if (amount < 0) {
		return ErrorCode::NotFound;
	}
	salary = amount;
	return ErrorCode::OK;
}

int Employee::getID()
{
	return id;
}

void const Employee::print()
{
	std::cout << "Id : " << id << std::endl;
	std::cout << "Name : ";
	for (int i = 0; i < strlen(name);i++) {
		std::cout << name[i];
	}
	std::cout << "Position : ";
	for (int i = 0; i < strlen(position);i++) {
		std::cout << position[i];
	}
	std::cout << salary;

}

std::strong_ordering Employee::operator<=>(Employee other)
{
	std::strong_ordering cmp;
	if (salary != other.salary) {
		if (salary < other.salary) {
			cmp = std::strong_ordering::less;
		}
		else if (salary > other.salary) {
			cmp = std::strong_ordering::greater;
		}
	}
	cmp = id <=> other.id;
	return cmp;
}

bool Employee::operator==(const Employee& other) const
{
	if (salary != other.salary) {
		return 0;
	}
	return 1;
}

bool Employee::operator<(const Employee& other) const
{
	if(salary<other.salary)
	return true;
	return false;
}

Employee& Employee::operator++()
{
	salary *= 1.1;
	return *this;
}

Employee& Employee::operator++(int dummy)
{
	Employee temp(*this);
	salary *= 1.1;
	return temp;
}


