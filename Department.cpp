#define _CRT_SECURE_NO_WARNINGS
#include "Department.h"
#include <iostream>

void Department::copyForm(const Department& other)
{
	if (other.name) {
		name = new char[std::strlen(other.name + 1)];
		std::strcpy(this->name, other.name);
	}
	else {
		name = nullptr;
	}
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;
	if (capacity > 0) {
		employees = new Employee[capacity];
		for (size_t i = 0; i < countOfEmployees; i++)
		{
			employees[i] = other.employees[i];
		}
	}
	else {
		employees = nullptr;
	}
}

void Department::free()
{
	delete[] name;
	delete[] employees;

	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}

ErrorCode Department::resize(unsigned newCapacity)
{
	if (newCapacity < countOfEmployees) {
		return ErrorCode::InvalidInput;
	}
	Employee* newEmployees = new Employee[newCapacity];
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		newEmployees = new Employee[i];
	}
	delete[]  employees;
	employees = newEmployees;
	capacity = newCapacity;
	return ErrorCode::OK;
	
}

double Department::averageSalary() const
{
	if (countOfEmployees == 0) {
		return 0.00;
	}

	double sum = 0;
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		sum += employees[i].getsalary();
	}
	sum = sum / countOfEmployees;
	return sum;
}

Department::Department()
	: name(nullptr), employees(nullptr), countOfEmployees(0), capacity(0)
{
}

Department::Department(const char* name, unsigned initialCapacity)
	: name(nullptr), employees(nullptr), countOfEmployees(0), capacity(initialCapacity)
{
	if (name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	if (capacity > 0)
	{
		employees = new Employee[capacity];
	}
}

Department::Department(const Department& other)
{
	copyForm(other);
}

Department& Department::operator=(const Department& other)
{
	if (this != &other) {
		free();
		copyForm(other);
	}
	return *this;
}

Department::Department(Department& other) noexcept
	:name(other.name),countOfEmployees(other.countOfEmployees),capacity(other.capacity),employees(other.employees)
{
	other.name = nullptr;
	other.employees = nullptr;
	other.countOfEmployees = 0;
	other.capacity = 0;

}

Department& Department::operator=(Department&& other) noexcept
{
	if (this != &other) {
		free();

		name = other.name;
		employees = other.employees;
		countOfEmployees = other.countOfEmployees;
		capacity = other.capacity;

		other.name = nullptr;
		other.employees = nullptr;
		other.countOfEmployees = 0;
		other.capacity = 0;
	}
	return *this;
}

Department::~Department()
{
	free();
}

char* Department::getName() const
{
	return name;
}

unsigned Department::getCountOfEmployees() const
{
	return countOfEmployees;
}

unsigned Department::getCapacity() const
{
	return capacity;
}

ErrorCode Department::addEmployee(const Employee& newEmployee)
{
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == newEmployee.getId()) {
			return ErrorCode::Duplicate;
		}
	}
	if (countOfEmployees > capacity) {
		unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;
		ErrorCode resizeResult = resize(newCapacity);
		if (resizeResult != ErrorCode::OK) {
			return resizeResult;
		}
	}
	employees[countOfEmployees++] = newEmployee;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id) {
	for (unsigned i = 0; i < countOfEmployees; i++) {
		if (employees[i].getId() == id) {
			for (unsigned j = i; j + 1 < countOfEmployees; j++) {
				employees[j] = employees[j + 1];
			}
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}

	return ErrorCode::NotFound;
}

Employee& Department::operator[](unsigned index) {
	if (index >= countOfEmployees) {
	 std::cout<<"Invalid employee index";
	}
	return employees[index];
}

const Employee& Department::operator[](unsigned index) const {
	if (index >= countOfEmployees) {
		std::cout<<"Invalid employee index";
	}
	return employees[index];
}

Department::operator bool() const {
	return countOfEmployees > 0;
}

Department& Department::operator()(double percent) {
	if (percent < 0) {
		std::cout<<"Percent cannot be negative";
	}

	for (unsigned i = 0; i < countOfEmployees; i++) {
		double newSalary = employees[i].getsalary() * (1.0 + percent / 100.0);
		employees[i].updateSalary(newSalary);
	}

	return *this;
}



std::ostream& operator<<(std::ostream& os, const Department& department) {
	os << department.getName()
		<< " " << department.getCountOfEmployees()
		<< " " << department.averageSalary() << '\n';

	for (unsigned i = 0; i < department.getCountOfEmployees(); i++) {
		os << "  - " << department.employees[i] << '\n';
	}

	return os;
}

bool operator<(const Department& d1, const Department& d2)
{
	if (d1.countOfEmployees == d2.countOfEmployees) {
		return d1.averageSalary() < d2.averageSalary();
	}
	return d1.countOfEmployees < d2.countOfEmployees;
}

bool operator>(const Department& d1, const Department& d2)
{
	return d2 < d1;
}

bool operator<=(const Department& d1, const Department& d2)
{
	return !(d2 < d1);
}

bool operator>=(const Department& d1, const Department& d2)
{
	return !(d1 < d2);
}

bool operator==(const Department& d1, const Department& d2)
{
	return d1.countOfEmployees == d2.countOfEmployees &&
		d1.averageSalary() == d2.averageSalary();
}

bool operator!=(const Department& d1, const Department& d2)
{
	return !(d1 == d2);
}





