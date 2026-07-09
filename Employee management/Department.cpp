#include <iostream>
using std::cout;
using std::string;
using std::cin;
using std::endl;
#define double_vs_double 
#include "Department.h"
Employee* ReSize(Employee* employees,int size,int new_size)
{
	Employee* arr = new Employee[new_size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = employees[i];
	}
	return arr;
}
double AVGSalary(Employee* arr,int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i].getSalary();
	}
	return sum / size;
}
double Mod(double a)
{
	if (a >= 0)
	{
		return a;
	}
	else
	{
		return -a;
	}
}
bool DoubleVsDouble(double a,double b)
{
	const double epsilon = 1e-10;
	if (Mod(a - b) - epsilon < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Department::Department()
{
	name = nullptr;
	employees = nullptr;
	countOfEmployees = 0;
	capacity = 0;
}
Department::Department(const char* n, unsigned c)
{
	int size_n = strlen(n);
	name = new char[size_n];
	for (int i = 0; i < size_n; i++)
	{
		name[i] = n[i];
	}
	employees = nullptr;
	countOfEmployees = 0;
	capacity = c;

}
ErrorCode Department::addEmployee(Employee e)
{
	bool check = true;
	ErrorCode error = ErrorCode::OK;
	for (int i = 0; i < countOfEmployees; i++)
	{
		if(employees[i] == e);
		{
			check = false;
			break;
		}
	}
	if (check)
	{
		countOfEmployees++;
		employees=ReSize(employees, countOfEmployees - 1,countOfEmployees);
		employees[countOfEmployees - 1] = e;
	}
	else
	{
		error = ErrorCode::Duplicate;
	}
	if (capacity < countOfEmployees)
	{
		capacity = countOfEmployees;
	}
	return error;
}
char* Department::getName()
{
	return name;
}
ErrorCode Department::removeEmployee(unsigned i)
{
	bool check = false;
	int index = 0;
	ErrorCode error = ErrorCode::OK;
	if (capacity < countOfEmployees)
	{
		capacity = countOfEmployees;
	}
	for (int i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].ReturnID() == i);
		{
			index = i;
			check = true;
			break;
		}
	}
	if (check)
	{
		Employee a = employees[index];
		employees[index] = employees[countOfEmployees - 1];
		employees[countOfEmployees - 1] = a;
		countOfEmployees--;
	}
	else
	{
		error = ErrorCode::NotFound;
	}
	return error;
}
std::ostream& operator<<(std::ostream& out, const Department& D)
{
	int size_n = strlen(D.name);
	out << "Name:";
	for (int i = 0; i < size_n; i++)
	{
		out << D.name[i];
	}
	out << endl << "Employees:" << endl;
	for (int i = 0; i < D.countOfEmployees; i++)
	{
		out << D.employees[i];
		out << endl;
	}
	out << endl;
	out << "Count of employees:" << D.countOfEmployees;
	out << endl;
	out << "Capacity:" << D.capacity;
	out << endl;
	return out;
}
Employee& Department::operator[](int index)
{
	return employees[index];
}
const Employee& Department::operator[](int index) const
{
	return employees[index];
}
Department::operator bool() const
{
	bool check = true;
	if (countOfEmployees==0)
	{
		check = false;
	}
	return check;
}
Department& Department::operator()(int parcent)
{
	
	for (int i = 0; i < countOfEmployees; i++)
	{
		double salary = (employees[i].getSalary() * parcent) / 100;
		employees[i].updateSalary(salary);
	}
	return *this;
}
bool operator<(const Department& D1, const Department& D2)
{
	bool check = true;
	if (D1.countOfEmployees > D2.countOfEmployees)
	{
		check = false;
	}
	if (D1.countOfEmployees == D2.countOfEmployees)
	{
		check = AVGSalary(D1.employees, D1.countOfEmployees) < AVGSalary(D2.employees, D2.countOfEmployees);
	}
	return check;
}
bool operator>(const Department& D1, const Department& D2)
{
	bool check = true;
	if (D1.countOfEmployees < D2.countOfEmployees)
	{
		check = false;
	}
	if (D1.countOfEmployees == D2.countOfEmployees)
	{
		check = AVGSalary(D1.employees, D1.countOfEmployees) > AVGSalary(D2.employees, D2.countOfEmployees);
	}
	return check;
}
bool operator==(const Department& D1, const Department& D2)
{
	bool check = false;
	if (D1.countOfEmployees == D2.countOfEmployees && DoubleVsDouble(AVGSalary(D1.employees, D1.countOfEmployees), AVGSalary(D2.employees, D2.countOfEmployees)))
	{
		check = true;
	}
	return check;
}