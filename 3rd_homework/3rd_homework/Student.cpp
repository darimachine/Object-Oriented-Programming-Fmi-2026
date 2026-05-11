#include "Student.h"
#include <stdexcept>
#include <iostream>
#include <print>
#include "Animal.h"

unsigned Student::ID = 1;

void Student::setCourse(int inpCourse)
{
	if (inpCourse < MIN_COURSE || inpCourse > MAX_COURSE)
	{
		throw std::invalid_argument("The inputed course is invalid");
	}
	else
	{
		course = inpCourse;
	}
}

Student::Student(const std::string& inpName, int inpCourse) : name(inpName)
{
	setCourse(inpCourse);
	personalID = ID;
	ID++;
}

const unsigned Student::getPersonalID() const
{
	return personalID;
}

void Student::displayStudentInfo() const
{
	std::println("Name: {}, faculty number:{}, course:{}", name, personalID, course);
}

const std::string& Student::getName() const
{
	return name;
}



const int Student::getCourse() const
{
	return course;
}

Student::Student(): name("No name"), course(MIN_COURSE), personalID(0)
{
}
