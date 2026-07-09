#include "Department.h"
#include <cstring>

void Department::copyFrom(const Department& other)
{
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;

	size_t size = strlen(other.name) + 1;
	name = new char[size];
	strcpy_s(name, size, other.name);

	employees = new Employee[capacity];

	if (countOfEmployees > capacity) {
		return;
	}

	for (size_t i = 0; i < countOfEmployees; i++)
	{
		employees[i] = other.employees[i];
	}
}

void Department::free()
{
	delete[] name;
	delete[] employees;
	name = nullptr;
	employees = nullptr;
}

void Department::moveFrom(Department&& other)
{
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;
	name = other.name;
	employees = other.employees;

	other.countOfEmployees = 0;
	other.capacity = DEFAULT_CAP;
	other.name = nullptr;
	other.employees = nullptr;
}

void Department::resize(unsigned newCap)
{

	if (capacity >= newCap) {
		return;
	}

	Employee* resized = new Employee[newCap];

	for (size_t i = 0; i < countOfEmployees; i++)
	{
		resized[i] = employees[i];
	}

	delete[] employees;
	employees = resized;
	capacity = newCap;
}

Department::Department() :Department(nullptr, DEFAULT_CAP)
{
}


Department::Department(const char* name, unsigned capacity):capacity(capacity)
{
	if (!name) {
		this->name = new char[1];
		this->name[0] = '\0';
		
	}
	else {
		size_t size = strlen(name) + 1;
		this->name = new char[size];
		strcpy_s(this->name, size, name);
	}

	this->employees = new Employee[capacity];
}

Department::Department(const Department& other)
{
	copyFrom(other);
}

Department& Department::operator=(const Department& other)
{
	if (this != &other) {
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
	if (this != &other) {
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

	for (size_t i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == employee.getId())
			return ErrorCode::Duplicate;
	}

	if (countOfEmployees >= capacity) {
		resize(capacity * 2);
	}

	employees[countOfEmployees++] = employee;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		if(employees[i].getId()==id){
			std::swap(employees[i], employees[countOfEmployees - 1]);
			countOfEmployees--;
			return ErrorCode::OK;
		}
	}
	
	return ErrorCode::NotFound;
}

const char* Department::getName() const
{
	return name;
}

double Department::getAverageSalary() const
{
	if (countOfEmployees == 0) {
		return 0.0;
	}
		
	double sum = 0.0;
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		sum += employees[i].getSalary();
	}

	return sum / countOfEmployees;
}

unsigned Department::getCount() const
{
	return countOfEmployees;
}

Employee& Department::operator[](unsigned index)
{
	return employees[index];
}

const Employee& Department::operator[](unsigned index) const
{
	return employees[index];
}

Department::operator bool() const
{
	return countOfEmployees > 0;
}

Department& Department::operator()(unsigned percentage)
{
	
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		double amount = (percentage / 100.0 + 1) * employees[i].getSalary();
		employees[i].updateSalary(amount);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Department& departm)
{
	os << departm.name << "\n";

	for (size_t i = 0; i < departm.countOfEmployees; i++)
	{
		os << departm.employees[i] << "\n";
	}
	return os;
}

bool operator==(const Department& lhs, const Department& rhs)
{
	return lhs.getCount() == rhs.getCount() && salaryEqual(lhs.getAverageSalary(), rhs.getAverageSalary());
}

std::strong_ordering operator<=>(const Department& lhs, const Department& rhs)
{
	auto cmp = lhs.getCount() <=> rhs.getCount();
	if (cmp != 0) {
		return cmp;
	}
		

	double lAvg = lhs.getAverageSalary();
	double rAvg = rhs.getAverageSalary();

	if (salaryEqual(lAvg, rAvg)) {
		return std::strong_ordering::equal;
	}
		
	if (lAvg < rAvg) {
		return std::strong_ordering::less;
	}
		
	return std::strong_ordering::greater;
}
