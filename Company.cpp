#define _CRT_SECURE_NO_WARNINGS
#include "Company.h"
#include<cstring>
#include<iostream>
#include <compare>

//Employee class
int Employee::nextID = 0;

Employee::Employee()
{
	id = generateID();
	name[0] = '\0';
	position[0] = '\0';
	salary = 0.0;
}

Employee::Employee(const char* _name, const char* _position, double _salary) : salary(_salary)
{
	id = generateID();
	strncpy(name, _name, 127);
	name[127] = '\0';

	strncpy(position, _position, 127);
	position[127] = '\0';
}


double Employee::getSalary() const
{
	return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (amount < 0)
		return ErrorCode::InvalidInput;

	salary += amount;
	return ErrorCode::OK;
}

int Employee::generateID()
{
	return ++nextID;
}

int Employee::getLastId()
{
	return nextID;
}

unsigned Employee::getId()
{
	return id;
}

std::partial_ordering Employee::operator<=>(const Employee& other) const
{
	auto cmpS = salary <=> other.salary;
	if (cmpS != 0) return cmpS;
	auto cmpId = id <=> other.id;
	return cmpId;
}

bool Employee::operator==(const Employee& other) const
{
	return (salary == other.salary && id == other.id);
}

Employee& Employee::operator++()
{
	this->salary += (10.0 / 100) * salary;
	return *this;
}

Employee Employee::operator++(int dummy)
{
	Employee temp = *this;
	++(*this);
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
	os << e.name << ", position "<< e.position << ", id " << e.id << ", salary " << e.salary;
	return os;
}



//Department class
Department::Department() : name(nullptr), employees(nullptr), countOfEmployees(0), capacity(0) {}

Department::Department(const char* _name, unsigned _capacity):capacity(_capacity), countOfEmployees(0)
{
	if (_name != nullptr)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	else
	{
		name = new char[1];
		name[0] = '\0';
	}

	employees = new Employee[capacity];
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

ErrorCode Department::addEmployee(const Employee& e)
{
	if (countOfEmployees == capacity) {
		if (capacity == 0) capacity = 1;//because resize is *2
		resize();
	}

	employees[countOfEmployees++] = e;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	for (int i = 0; i < countOfEmployees; i++) {
		if (employees[i].getId() == id)
		{
			for (int j = i; j < countOfEmployees - 1; j++)
			{
				employees[j] = employees[j + 1];//shift left
			}
			countOfEmployees--;//remove the last element
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

double Department::avgSal() const
{
	if (countOfEmployees == 0) return 0;
	double sumSal = 0;
	for (int i = 0; i < countOfEmployees; i++)
	{
		sumSal += employees[i].getSalary();
	}
	double avgSal = sumSal / countOfEmployees;
	return avgSal;
}

Employee& Department::operator[](int index)
{
	if(index < 0 || index >= countOfEmployees)
		throw std::out_of_range("Index invalid!");
	return employees[index];
}

const Employee& Department::operator[](int index) const
{
	if (index < 0 || index >= countOfEmployees)
		throw std::out_of_range("Index invalid!");
	return employees[index];
}

const char* Department::getName() const
{
	return name ? name : "";
}

Department& Department::operator()(double percent)
{
	for (int i = 0; i < countOfEmployees; i++)
	{
		employees[i].updateSalary( employees[i].getSalary() * percent / 100.0 );
	}
	return *this;
}

Department::operator bool() const
{
	return countOfEmployees > 0;
}

std::partial_ordering Department::operator<=>(const Department& other) const
{
	auto cmp = countOfEmployees <=> other.countOfEmployees;
	if (cmp != 0) return cmp;
	return avgSal() <=> other.avgSal();
}

std::ostream& operator<<(std::ostream& os, const Department& d)
{
	os << "Department: " << (d.name ? d.name : "") << "\n";

	for (int i = 0; i < d.countOfEmployees; i++) {
		os << d.employees[i] << "\n";
	}
	return os;
}


void Department::resize() {
	capacity *= 2;
	Employee* temp = new Employee[capacity];

	for (int i = 0; i < countOfEmployees; i++) {
		temp[i] = employees[i];
	}

	delete[] employees;
	employees = temp;
}

void Department::free() {
	delete[] name;
	delete[] employees;

	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}
void Department::copyFrom(const Department& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	capacity = other.capacity;
	countOfEmployees = other.countOfEmployees;

	employees = new Employee[capacity];

	for (int i = 0; i < countOfEmployees; i++) {
		employees[i] = other.employees[i];
	}
}
void Department::moveFrom(Department&& other) {
	name = other.name;
	employees = other.employees;
	other.name = nullptr;
	other.employees = nullptr;
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;
	other.countOfEmployees = 0;
	other.capacity = 0;
}

//Company class

Company::operator bool() const
{
	for (int i = 0; i < countOfDepartments; i++) {
		if (departments[i])
			return true;
	}
	return false;
}

Department* Company::operator[](const char* depName)
{
	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), depName) == 0)
			return &departments[i];
	}
	return nullptr;
}

const Department* Company::operator[](const char* depName) const
{
	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), depName) == 0)
			return &departments[i];
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Company& c)
{
	for (int i = 0; i < c.countOfDepartments; i++) {
		os << c.departments[i] << "\n";
	}
	return os;
}

Company::Company() : countOfDepartments(0) {}

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
	if (!name)
		return ErrorCode::InvalidInput;

	if (countOfDepartments >= 10)
		return ErrorCode::Full;

	for (int i = 0; i < countOfDepartments; i++) {
		if (strcmp(departments[i].getName(), name) == 0)
			return ErrorCode::Duplicate;
	}

	departments[countOfDepartments++] = Department(name, 2);
	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0) {

			for (int j = i; j < countOfDepartments - 1; j++)
			{
				//shift left
				departments[j] = departments[j + 1];
			}

			countOfDepartments--;
			return ErrorCode::OK;
		}
	}
	return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			ErrorCode result = departments[i].addEmployee(employee);
			return result;
		}
	}
	return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
	for (int i = 0; i < countOfDepartments; i++) {
		if (strcmp(departments[i].getName(), departmentName) == 0) {
			ErrorCode result = departments[i].removeEmployee(id);
			return result;
		}
	}
	return ErrorCode::NotFound;
}