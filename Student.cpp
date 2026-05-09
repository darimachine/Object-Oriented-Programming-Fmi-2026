#include "Student.h"

Student::Student(): name("Unknown"), id(0), course(1) {}

Student::Student(std::string name, unsigned int id, int course) : name(name), id(id), course(course) {}

void Student::print() const
{
std::print("Name: {}, Id: {}, Course: {}\n", name, id, course);
}


