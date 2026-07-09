#include "Department.h"
#pragma warning(disable: 4996)


void Department::doubleCapacity()
{
	Employee* temp = new Employee[capacity * 2];
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		temp[i] = employees[i];
	}
	capacity *= 2;
	delete[] employees;
	employees = temp;
}

double Department::avgSalary() const
{
	double sum = 0;
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		sum += employees[i].getSalary();
	}
	sum /= countOfEmployees;
	return sum;
}

Department::Department()
{
	name = new char[128];

	strcpy(name, "Default name");
	capacity = 8;
	employees = new Employee[capacity];
	countOfEmployees = 0;
}

Department::Department(const char* _name)
{
	name = new char[128];

	strcpy(name, _name);
	capacity = 8;
	employees = new Employee[capacity];
	countOfEmployees = 0;
}

char* Department::getName()
{
	return this-> name;
}

Department::Department(const Department& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->capacity = other.capacity;
	this->countOfEmployees = other.countOfEmployees;

	this->employees = new Employee[this->capacity];

	for (size_t i = 0; i < countOfEmployees; i++)
	{
		this->employees[i] = other.employees[i];
	}
}

Department& Department::operator=(const Department& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] employees;

		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);

		capacity = other.capacity;
		countOfEmployees = other.countOfEmployees;

		employees = new Employee[capacity];

		for (size_t i = 0; i < countOfEmployees; i++)
		{
			employees[i] = other.employees[i];
		}
	}

	return *this;
}

Department::~Department()
{
	delete[] name;
	delete[] employees;
}
ErrorCode Department::addEmployee(const Employee& _empl)
{
	if (countOfEmployees>=capacity)
	{
		doubleCapacity();
	}
	employees[countOfEmployees++] = _empl;
	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(const unsigned int id)
{
	if (id>=countOfEmployees)
	{
		return ErrorCode::InvalidInput;
	}

	for (int i = id; i < countOfEmployees-1; i++)
	{
		employees[i] = employees[i+1];
	}
	countOfEmployees--;
	return ErrorCode::OK;
}

bool Department::operator==(const Department& other) const
{
	if (this->countOfEmployees==other.countOfEmployees)
	{
		return true;
	}
	double sum = avgSalary() - other.avgSalary();
	if (sum<0.0001)
	{
		return true;
	}

	return false;
}

Employee& Department::operator[](int id)
{
	return employees[id];
}

Employee& Department::operator[](int id) const
{
	return employees[id];
}

Department::operator bool()
{
	if (this == nullptr) {
		return false;
	}
	return countOfEmployees > 0;
}

std::strong_ordering Department::operator<=>(const Department& other) const
{

	if (*this==other)
	{
		return std::strong_ordering::equal;
	}
	if (this->countOfEmployees == other.countOfEmployees)
	{
		double sum = avgSalary() - other.avgSalary();//12   10
		if (sum > 0.0001)
		{
			return std::strong_ordering::greater;
		}
		else if (sum < -0.0001)
		{
			return std::strong_ordering::less;
		}
		
	}
	else if (this->countOfEmployees > other.countOfEmployees)
	{
		return std::strong_ordering::greater;

	}
	else {
		return std::strong_ordering::less;
	}
	return std::strong_ordering();
}

std::ostream& operator<<(std::ostream& os, const Department& d)
{
	os << "Department name: " <<d.name<<";\n Department Employee count: "<<d.countOfEmployees<<";\n Employees: \n";
	for (int i = 0; i < d.countOfEmployees; i++)
	{
		os << d[i];
	}

	return os;
}

Department& Department::operator()(double perc)
{
	for (size_t i = 0; i < countOfEmployees; i++)
	{
		employees[i].updateSalary(employees[i].getSalary() * (1 + perc));
	}

	return *this;
}

Department::Department(Department&& other)
{
	name = other.name;
	employees = other.employees;
	countOfEmployees = other.countOfEmployees;
	capacity = other.capacity;

	other.name = nullptr;
	other.employees = nullptr;
	other.countOfEmployees = 0;
	other.capacity = 0;

}


Department& Department::operator=(Department&& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] employees;

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