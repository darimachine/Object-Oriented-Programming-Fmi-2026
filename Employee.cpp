#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

unsigned Employee::nextId = 1;
unsigned Employee::lastInitializeId = 0;

void Employee::copyText(char* dest, const char* src, std::size_t maxLen)
{
	if (!src) {
		dest[0] = '\0';
		return;
	}
	std::strncpy(dest, src, maxLen);
	dest[maxLen] = '\0';
}

Employee::Employee()
{
	id = nextId;
	lastInitializeId = nextId;
	nextId++;
	name[0] = '\0';
	position[0] = '\0';
	salary = 0.00;


	
}

Employee::Employee(const char* name,const char* position, double salary)
{
	id = nextId;
	lastInitializeId = nextId;
	nextId++;
	copyText(this->name, name, 127);
	copyText(this->position, position, 127);
	if (salary < 0) {
		salary = 0.00;
	}
	else {
		this->salary = salary;
	}

}

unsigned Employee::getId() const
{
	return id;
}

const char* Employee::getName() const
{
	return name;
}

const char* Employee::getPosition() const
{
	return position;
}

double Employee::getsalary() const
{
	return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
	if(amount < 0) {
		return ErrorCode::InvalidInput;
	}
	else if (salary == amount) {
		return ErrorCode::Duplicate;
	}
	else {
		salary = amount;
		return ErrorCode::OK;
	}
}

unsigned Employee::lastIdPerson()
{
	return lastInitializeId;
}

Employee& Employee::operator++()
{
	salary *= 1.10;
	return *this;
}

Employee Employee::operator++(int)
{
	Employee temp = *this;
	salary *= 1.10;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
	os << employee.id << " " << employee.name << "  " << employee.position << " " << employee.salary;
	return os;
}

bool operator<(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id < e2.id;
	}
	return e1.salary < e2.salary;
}

bool operator>(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id > e2.id;
	}
	return e1.salary > e2.salary;
}

bool operator<=(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id <= e2.id;
	}
	return e1.salary <= e2.salary;
}

bool operator>=(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id >= e2.id;
	}
	return e1.salary >= e2.salary;
}

bool operator==(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id == e2.id;
	}
	return false;
}

bool operator!=(const Employee& e1, const Employee& e2)
{
	if (e1.salary == e2.salary) {
		return e1.id != e2.id;
	}
	return true;
}






