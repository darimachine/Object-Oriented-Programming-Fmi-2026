#define _CRT_SECURE_NO_WARNINGS
#include "Department.h"
#include<print>

Department::Department() :name(nullptr),countOfEmployees(0), capacity(DEFAULT_CAPACITY)
{
	employees = new Employee[capacity];
}

Department::Department(const char* name, unsigned capacity):capacity(capacity)
{
	setName(name);
	employees = new Employee[capacity];
}

void Department::setName(const char* name)
{
	if (name == nullptr)
	{
		return;
	}

	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Department::getName()const
{
	return name;
}

void Department::copyFrom(const Department& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;
	employees = new Employee[capacity];

	for (size_t i = 0;i < countOfEmployees;i++)
	{
		employees[i] = other.employees[i];
	}
}

void Department::moveFrom(Department&& other)
{
	name = other.name;
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;
	employees = other.employees;

	other.name = nullptr;
	other.countOfEmployees = 0;
	other.capacity = 0;
	other.employees = nullptr;
}

void Department::free()
{
	delete[]name;
	name = nullptr;

	delete[]employees;
	employees = nullptr;

	countOfEmployees = 0;
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

Department::Department(Department&& other)noexcept
{
	moveFrom(std::move(other));
}

Department& Department::operator=(Department&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Department::~Department()
{
	free();
}

void Department::resize(size_t newCap)
{
	capacity = newCap;
	Employee* resized = new Employee[capacity];

	for (size_t i = 0;i < countOfEmployees;i++)
	{
		resized[i] = employees[i];
	}

	delete[]employees;
	employees = resized;
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (countOfEmployees == capacity)
	{
		resize(capacity * 2);
	}
	employees[countOfEmployees++] = employee;
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
				employees[j] = employees[j + 1];
			}
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

std::ostream& operator<<(std::ostream& os, const Department& department)
{
	os << "Department: " << department.name << '\n';
	for (size_t i = 0;i < department.countOfEmployees;i++)
	{
		os << department.employees[i];
	}
	os << '\n';
	return os;
}

double Department::getAverageSalary()const
{
	if (countOfEmployees == 0)
	{
		return 0;
	}

	double sum = 0;

	for (size_t i = 0;i < countOfEmployees;i++)
	{
		sum += employees[i].getSalary();
	}

	return sum / countOfEmployees;
}

unsigned Department::getCount()const
{
	return countOfEmployees;
}

bool operator==(const Department& lhs, const Department& rhs)
{
	return isEqualSalary(lhs.getAverageSalary(), rhs.getAverageSalary()) &&
		lhs.getCount() == rhs.getCount();
}

std::strong_ordering operator<=>(const Department& lhs, const Department& rhs)
{
	auto cmpCount = lhs.getCount() <=> rhs.getCount();

	if (cmpCount != 0)
	{
		return cmpCount;
	}

	auto cmpSalary = lhs.getAverageSalary() <=> rhs.getAverageSalary();

	if (cmpSalary != 0)
	{
		if (cmpSalary < 0)
		{
			return std::strong_ordering::less;
		}
		else
		{
			return std::strong_ordering::greater;
		}
	}

	return std::strong_ordering::equal;
}

Employee& Department::operator[](size_t index)
{
	return employees[index];//exception for index if it is out of range
}

const Employee& Department::operator[](size_t index)const
{
	return employees[index];////exception for index if it is out of range
}

Department::operator bool()const
{
	return countOfEmployees > 0;
}

Department& Department::operator()(double percent)
{
	for (size_t i = 0;i < countOfEmployees;i++)
	{
		percent /= 100.0;
		double update = employees[i].getSalary() * percent;
		employees[i].updateSalary(update);
	}
	return *this;
}