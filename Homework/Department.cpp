#include "Department.h"

Department::Department()
{
	name = new char[5]{"Dep1"};
	employees = new Employee[5];
	unsigned countOfEmployees = 5;
	unsigned capacity = 5;
}

Department::Department(char* _name, unsigned _capacity)
{
	name = new char[strlen(_name)]{ *_name };
	employees = new Employee[_capacity];
	countOfEmployees = 0;
}

Department::Department(const Department& other)
{
		copyFrom(other);
}

Department Department::operator=(const Department& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
}

void Department::setName(const char* _name)
{
	*name = *_name;
}

char* Department::getName()
{
	return name;
}

void Department::copyFrom(const Department other)
{
	name = new char[strlen(other.name)] {*other.name};
	employees = new Employee[other.capacity];
	for (int i = 0;i < other.countOfEmployees;i++) {
		employees[i] = other.employees[i];
	}
	capacity = other.capacity;
	countOfEmployees = other.countOfEmployees;
}

void Department::free()
{
	delete[] name;
	delete[] employees;
	name = nullptr;
	employees = nullptr;
}

void Department::resize()
{
	Employee* temp = new Employee[capacity * 2];
	for (int i = 0;i < countOfEmployees;i++) {
		temp[i] = employees[i];
	}
	delete[] employees;
	employees = temp;
	capacity *= 2;


}

char* Department::getName() const
{
	return name;
}

ErrorCode Department::addEmployee(Employee other)
{
	if (countOfEmployees >= capacity) {
		resize();
		if (other.getID() >= Employee::getID()) {
			employees[countOfEmployees + 1] = other;
			countOfEmployees++;
			return ErrorCode::OK;
		}
		else {
			return ErrorCode::InvalidInput;
		}
	}
	else {
		if (other.getID() >= Employee::getID()) {
			employees[countOfEmployees + 1] = other;
			countOfEmployees++;
			return ErrorCode::OK;
		}
		else {
			return ErrorCode::InvalidInput;
		}
	}

}

ErrorCode Department::removeEmployee(unsigned int id)
{
	if (id > Employee::getID()) {
		for (int i = countOfEmployees-2;i >= id;i--) {
			employees[i] = employees[i + 1];
		}
		countOfEmployees--;
		return ErrorCode::OK;
	}
	else {
		return ErrorCode::NotFound;
	}
}

void Department::print()
{
	std::cout << *name << std::endl;
	for (int i = 0;i < countOfEmployees;i++) {
		employees[i].print();
		std::cout << std::endl;
	}

	 
}

std::strong_ordering Department::operator<=>(const Department& other)
{
	return std::strong_ordering();
}


Employee Department::operator[](int index)
{
	if (index <= countOfEmployees && index > 0)
		return employees[index];
}

Employee Department::operator[](int index) const
{
	if (index <= countOfEmployees && index > 0)
		return employees[index];
}

bool Department::active()
{
	if ((countOfEmployees) > 0)
		return true;
	return false;
}

Department& Department::operator()(double percent)
{
	for (int i = 0;i < countOfEmployees;i++) {
		double salaryNew = employees[i].getSalary();
		employees[i].updateSalary(salaryNew * percent);
	}
}

	double Department::averageSalary() const
{
	double sum=0;
	for (int i = 0;i < countOfEmployees;i++) {
		sum += employees[i].getSalary();
	}
	return sum / countOfEmployees;
}

	Department::~Department()
	{
		free();
	}


std::strong_ordering Department::operator<=>(const Department& other)
{
	std::strong_ordering cmp;
	cmp = countOfEmployees <=> other.countOfEmployees;
	if (cmp != 0) {
		return cmp;
	}
	else {
		if (averageSalary() < other.averageSalary()) {
			return std::strong_ordering::less;
		}
		if (averageSalary() > other.averageSalary()) {
			return std::strong_ordering::greater;
		}
		return std::strong_ordering::equal;

	}
}
