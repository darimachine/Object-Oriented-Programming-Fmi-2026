#pragma once
#include <string>
#include <print>
class Student
{
	static unsigned facultyNumber_gen;

	std::string name;
	unsigned faculty_number;
	unsigned course;
public:
	Student();
	Student(std::string name, unsigned course);

	const std::string& getName() const;
	void setName(std::string name);

	unsigned getCourse() const;
	void setCourse(unsigned course);

	unsigned getFacultyNumber() const;
};

