#include "Department.h"

void Department::free()
{
	delete[] this->employees;
	delete[] this->name;
}

void Department::copyFrom(const Department& other)
{
	this->countOfEmployees = other.countOfEmployees;
	this->capacity = other.capacity;
	this->employees = new Employee[this->capacity];
	this->name = new char[strlen(other.name) + 1];
	for (unsigned i = 0; i < other.countOfEmployees; i++)
	{
		this->employees[i] = other.employees[i];
	}
	strcpy(this->name, other.name);
	this->name[strlen(this->name)] = '\0';
}

void Department::moveFrom(Department&& other) noexcept
{
	this->employees = other.employees;
	other.employees = nullptr;
	this->capacity = other.capacity;
	other.capacity = 0;
	this->countOfEmployees = other.countOfEmployees;
	other.countOfEmployees = 0;
	this->name = other.name;
	other.name = nullptr;
}

void Department::resize(unsigned newCap)
{
	Employee* temp = new Employee[newCap];
	for (unsigned i = 0; i < this->countOfEmployees; i++)
	{
		temp[i] = this->employees[i];
	}
	this->capacity = newCap;
	delete[] this->employees;
	this->employees = temp;
}

Department::Department() : Department("Unnamed Department", 8)
{ }

Department::Department(const char* name, unsigned capacity)
{
	if (!name)
	{
		std::cerr << "Invalid name. Try again";
		return;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';
	this->countOfEmployees = 0;
	this->capacity = capacity;
	this->employees = new Employee[this->capacity];
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

Department::Department(Department&& other) noexcept
{
	moveFrom(std::move(other));
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

Department::~Department()
{
	free();
}

ErrorCode Department::addEmployee(const Employee& employee)
{
	if (this->countOfEmployees == this->capacity)
	{
		resize(this->capacity * 2);
	}
	this->employees[countOfEmployees++] = employee;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	if (id >= countOfEmployees) return ErrorCode::InvalidInput;
	for (unsigned i = 0; i < this->countOfEmployees; i++)
	{
		if (this->employees[i].getId() == id)
		{
			std::swap(this->employees[countOfEmployees - 1], this->employees[i]);
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

double Department::getAverageSalary() const
{
	if (this->countOfEmployees == 0) return 0;
	double avg = 0;
	for (unsigned i = 0; i < this->countOfEmployees; i++)
	{
		avg += this->employees[i].getSalary();
	}
	return avg / (double)countOfEmployees;
}

const char* Department::getName() const
{
	return this->name;
}

Employee& Department::operator[](size_t index)
{
	return this->employees[index];
}

const Employee& Department::operator[](size_t index) const
{
	return this->employees[index];
}

Department::operator bool() const
{
	return this->countOfEmployees > 0;
}

Department& Department::operator()(double percent)
{
	for (unsigned i = 0; i < this->countOfEmployees; i++)
	{
		this->employees[i].updateSalary(this->employees[i].getSalary() + this->employees[i].getSalary() * percent);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Department& department)
{
	os << department.name << ' ' << department.countOfEmployees << " employees" << '\n';
	for (unsigned i = 0; i < department.countOfEmployees; i++)
	{
		os << department.employees[i];
	}
	return os;
}

bool operator<(const Department& dep1, const Department& dep2)
{
	if (dep1.countOfEmployees != dep2.countOfEmployees)
	{
		return dep1.countOfEmployees < dep2.countOfEmployees;
	}

	return dep1.getAverageSalary() < dep2.getAverageSalary();
}

bool operator==(const Department& dep1, const Department& dep2)
{
	if (dep1.countOfEmployees == dep2.countOfEmployees && dep1.getAverageSalary() == dep2.getAverageSalary()) return true;
	return false;
}

bool operator>(const Department& dep1, const Department& dep2)
{
	return dep2 < dep1;
}
