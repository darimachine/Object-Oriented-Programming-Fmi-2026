#include "Student.h"
#include <iostream>
#include "StudentException.h"
#include "StudentDB.h"

Student::Student() : name("Unknown"), facultyNumber(0), year(1) 
{

}

Student::Student(std::string name, unsigned facultyNumber, int year)
{
	if (name.empty()) 
	{
		throw StudentException("Name cannot be empty!");
	}

	if (year < 1 || year > 5)
	{
		throw StudentException("Invalid course.");
	}

	if (facultyNumber < 10000 || facultyNumber > 99999) 
	{
		throw StudentException("FN must be at least 5 characters");
	}
	this->name = name;
	this->facultyNumber = facultyNumber;
	this->year = year;
}

unsigned Student::getFN() const
{
	return facultyNumber;
}

std::string Student::getName() const
{
	return name;
}

int Student::getYear() const
{
	return year;
}

void Student::display() const
{
	std::cout << "Name: " << name
		<< " | FN: " << facultyNumber
		<< " | Year: " << year << std::endl;
}