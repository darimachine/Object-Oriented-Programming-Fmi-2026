#define _CRT_SECURE_NO_WARNINGS

#include "Department.h"
#include <cstring>
#include <cmath>

void Department::resize()
{
	this->capacity *= 2;
	Employee* newEmployees = new Employee[capacity];
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		newEmployees[i] = employees[i];
	}
	delete[] employees;
	employees = newEmployees;
}

void Department::copyFrom(const Department& other)
{
	this->capacity = other.capacity;
	this->countOfEmployees = other.countOfEmployees;

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->employees = new Employee[capacity];
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		this->employees[i] = other.employees[i];
	}
}

void Department::moveFrom(Department&& other)
{
	this->capacity = other.capacity;
	this->countOfEmployees = other.countOfEmployees;
	this->name = other.name;
	this->employees = other.employees;

	other.name = nullptr;
	other.employees = nullptr;
	other.countOfEmployees = 0;
	other.capacity = 0;
}

void Department::free()
{
	delete[] name;
	delete[] employees;
	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 8;
}

Department::Department() : countOfEmployees(0), capacity(8)
{
	employees = new Employee[capacity];
	name = new char[1];
	name[0] = '\0';
}

Department::~Department()
{
	free();
}

Department::Department(const Department& other)
{
	copyFrom(other);
}

Department::Department(Department&& other) noexcept
{
	moveFrom(std::move(other));
}

Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Department& Department::operator=(Department&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Department::Department(const char* name, unsigned capacity) : capacity(capacity)
{
	employees = new Employee[capacity];
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (countOfEmployees + 1 == capacity)
	{
		resize();
	}

	employees[countOfEmployees++] = employee;

	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	if (countOfEmployees == 0)
	{
		return ErrorCode::NotFound;
	}
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id) {
			{
				employees[i] = employees[--countOfEmployees];
				return ErrorCode::OK;
			}
		}
	}

	return ErrorCode::NotFound;
}

bool Department::operator==(const Department& other) const
{
	return countOfEmployees == other.countOfEmployees && std::abs(getAverageSalary() - other.getAverageSalary()) < EPSILON;
}

Employee& Department::operator[](unsigned index)
{
	if (index >= countOfEmployees)
	{
		throw std::out_of_range("Index out of range");
	}

	return employees[index];
}

const Employee& Department::operator[](unsigned index) const
{
	if (index >= countOfEmployees)
	{
		throw std::out_of_range("Index out of range");
	}

	return employees[index];
}

std::strong_ordering Department::operator<=>(const Department& other) const
{
	if (auto cmp = countOfEmployees <=> other.countOfEmployees; cmp != 0)
	{
		return cmp;
	}
	
	double avg1 = getAverageSalary();
	double avg2 = other.getAverageSalary();

	if (std::abs(avg1 - avg2) < EPSILON) {
		return std::strong_ordering::equal;
	}

	return (avg1 < avg2) ? std::strong_ordering::less : std::strong_ordering::greater;
}

std::ostream& operator<<(std::ostream& os, const Department& department)
{
	os << "Department: " << department.name << std::endl 
		<< "Employees: " << std::endl; 

	for (unsigned i = 0; i < department.countOfEmployees; i++) {
		os << department.employees[i] << std::endl;
	}
	
	return os;
}

Department::operator bool() const {
	return countOfEmployees > 0;
}

Department& Department::operator()(double percentage) {
	for (unsigned i = 0; i < countOfEmployees; i++) {
		double current = employees[i].getSalary();
		double newSalary = current + (current * percentage / 100.0);
		employees[i].updateSalary(newSalary);
	}
	return *this;
}

double Department::getAverageSalary() const
{
	if (countOfEmployees == 0)
	{
		return 0;
	}

	double sum = 0;
	for (unsigned i = 0; i < countOfEmployees; i++)
	{
		sum += employees[i].getSalary();
	}

	return sum / countOfEmployees;
}
