#include "Student.h"

unsigned Student::nextId = 0;

Student::Student(const string& name, const string& course):
	id(++nextId),name(name),course(course){}

unsigned Student::getId()const
{
	return id;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
	return os << s.id << ' ' << s.name << ' ' << s.course << '\n';
}