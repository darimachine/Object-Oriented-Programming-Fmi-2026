#include "Student.h"

unsigned Student::facultyNumber_gen = 1;

Student::Student() : Student("Unnamed", 1)
{
}

Student::Student(std::string name, unsigned course)
{
	setName(std::move(name));
	setCourse(course);
	this->faculty_number = facultyNumber_gen++;
}

const std::string& Student::getName() const
{
	return name;
}

void Student::setName(std::string name)
{
	if (!name.empty()) this->name = std::move(name);
}

unsigned Student::getCourse() const
{
	return course;
}

void Student::setCourse(unsigned course)
{
	if (course > 0) this->course = course;
}

unsigned Student::getFacultyNumber() const
{
	return faculty_number;
}
