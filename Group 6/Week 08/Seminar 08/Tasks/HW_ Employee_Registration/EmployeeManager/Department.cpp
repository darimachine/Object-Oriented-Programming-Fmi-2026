#pragma warning (disable : 4996)
#include "Department.h"
#include <cstring>

void Department::copyFrom(const Department& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->employees = new Employee[other.capacity];
	for (size_t i = 0; i < other.countOfEmployees; i++)
	{
		this->employees[i] = other.employees[i];
	}
	this->countOfEmployees = other.countOfEmployees;
	this->capacity = other.capacity;
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

void Department::resize()
{
	capacity *= 2;
	
	Employee* newArr = new Employee[capacity];

	for (size_t i = 0; i < countOfEmployees; i++)
	{
		newArr[i] = employees[i];
	}

	delete[] employees;
	employees = newArr;
}

Department::Department(char* name, unsigned intialCapacity): countOfEmployees(0), capacity(intialCapacity)
{
	this->name = new char[std::strlen(name) + 1];
	if (this->name)
	{
		strcpy(this->name, name);
	}

	employees = new Employee[capacity];
	if (!employees)
		capacity = 0;
}

Department::Department(const char* name, unsigned intialCapacity) : countOfEmployees(0), capacity(intialCapacity)
{
	this->name = new char[std::strlen(name) + 1];
	if (this->name)
	{
		strcpy(this->name, name);
	}

	employees = new Employee[capacity];
	if (!employees)
		capacity = 0;
}

Department::Department(const Department& other)
{
	copyFrom(other);
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

Department::~Department()
{
	free();
}

double Department::getAverageSalary() const
{
	if (countOfEmployees == 0.0)
	{
		return 0.0;
	}

	double total = 0;
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		total += employees[i].getSalary();
	}

	return total / countOfEmployees;
}

ErrorCode Department::addEmployee(const Employee& emp)
{
	if (countOfEmployees == capacity)
	{
		resize();
	}

	employees[countOfEmployees++] = emp;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id)
		{
			for (size_t j = i; j < countOfEmployees - 1; j++)
			{
				employees[j] = employees[j+1];
			}

			countOfEmployees--;
			return ErrorCode::OK;
		}
	}

	return ErrorCode::NotFound;
}

bool Department::operator==(const Department& other) const
{
	return std::strcmp(name, other.name) == 0;
}

Employee& Department::operator[](unsigned index)
{
	if (index >= countOfEmployees)
		throw std::out_of_range("Department index out of range.");

	return employees[index];
}

const Employee& Department::operator[](unsigned index) const
{
	if (index >= countOfEmployees)
		throw std::out_of_range("Department index out of range.");

	return employees[index];
}

Department& Department::operator()(double percent)
{
	if (percent < 0.0)
	{
		//throw std::out_of_range("Percent out of range.")
		return *this;
	}

	for (size_t i = 0; i < countOfEmployees;i++)
	{
		double newSalary = employees[i].getSalary() * (1.0 + percent / 100);
		employees[i].updateSalary(newSalary);
	}

	return *this;
}

// <=> : primary key = countOfEmployees (strong), secondary = averageSalary (partial)
std::partial_ordering Department::operator<=>(const Department& other) const
{
	if (auto cmp = countOfEmployees <=> other.countOfEmployees;  cmp!= 0)
	{
		return cmp;
	}

	return getAverageSalary() <=> other.getAverageSalary();
}

std::ostream& operator<<(std::ostream& os, const Department& dep)
{
	os << "Department: " << dep.name << " (" << dep.countOfEmployees << " employees)\n";

	for (unsigned i = 0; i < dep.countOfEmployees; ++i)
		os << dep.employees[i] << '\n';
	return os;
}
