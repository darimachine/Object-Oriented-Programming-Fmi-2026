#include <iostream>
using std::cout;
using std::string;
using std::cin;
using std::endl;
#include "Employee.h"
unsigned Employee::br = 0;
Employee::Employee()
{
	br++;
	id = br;
	salary = 0;
}
Employee::Employee(char* n, char* p, double s)
{
	br++;
	id = br;
	int size_n = strlen(n);
	int size_p = strlen(p);
	if (size_n <= SIZE)
	{
		if (size_p < SIZE)
		{
			for (int i = 0; i < size_n; i++)
			{
				name[i] = n[i];
			}
			for (int i = 0; i < size_p; i++)
			{
				position[i] = p[i];
			}
			salary = s;
		}
		else
		{
			cout << "The position length is longer than the maximum allowed.";
		}
	}
	else
	{
		cout << "The name length is longer than the maximum allowed.";
	}
	
}
double Employee::getSalary() const
{
	if (salary > 0)
	{
		return salary;
	}
	else
	{
		cout << "The salary can't be less then zero. Now is zero.";
		salary = 0;
		return salary;
	}
}
ErrorCode Employee::updateSalary(double amount)
{
	ErrorCode e = ErrorCode::OK;
	if (amount > 0)
	{
		salary += amount;
	}
	else
	{
		ErrorCode e = ErrorCode::InvalidInput;
	}
	return e;
	

}
unsigned Employee::ReturnID()
{
	return br;
}
std::ostream& operator<<(std::ostream& out, const Employee& E)
{
	int size_n = strlen(E.name);
	int size_p = strlen(E.position);
	out << "ID:" << E.ReturnID() << endl;
	out << "Name:";
	for (int i = 0; i < size_n; i++)
	{
		out << E.name[i];
	}
	out<<endl << "Position:";
	for (int i = 0; i < size_p; i++)
	{
		out << E.position[i];
	}
	out << endl;
	out << "Salary:" << E.getSalary() << endl;
	return out;
}
Employee& Employee::operator++()
{
	salary += salary / 10;
	return *this;
}
Employee Employee::operator++(int prefix)
{
	Employee e = *this;
	e.salary += e.salary / 10;
	return e;
}
bool operator<(const Employee& D1, const Employee& D2)
{
	bool check = true;
	if (D1.getSalary() > D2.getSalary())
	{
		check = false;
	}
	if (D1.getSalary() == D2.getSalary())
	{
		check = D1.ReturnID() < D2.ReturnID();
	}
	return check;
}
bool operator>(const Employee& D1, const Employee& D2)
{
	bool check = true;
	if (D1.getSalary() < D2.getSalary())
	{
		check = false;
	}
	if (D1.getSalary() == D2.getSalary())
	{
		check = D1.ReturnID() > D2.ReturnID();
	}
	return check;
}
bool operator==(const Employee& D1, const Employee& D2)
{
	bool check = false;
	if (D1.getSalary() == D2.getSalary() && D1.ReturnID() == D2.ReturnID())
	{
		check = true;
	}
	return check;
}
