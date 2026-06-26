#include "Student.h"

unsigned int Student::counter = 0;

Student::Student() : facultyNumber(0), course(0) {}

Student::Student(const std::string& name, short course) : name(name), course(course)
{
    facultyNumber = counter++;
}

const std::string Student::getName() const
{
    return name;
}

unsigned Student::getFacultyNumber() const
{
    return facultyNumber;
}

short Student::getCourse() const
{
    return course;
}

void Student::print() const
{
    std::cout << "Name: " << name
        << ", FN: " << facultyNumber
        << ", Course: " << course << "\n";
}
