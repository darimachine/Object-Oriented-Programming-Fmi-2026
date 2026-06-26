#pragma once
#include <string>
#include <iostream>

class Student
{
private:
	std::string name;
	static unsigned int counter;
	unsigned facultyNumber;
	short course;

public:
	Student();
	Student(const std::string& name, short course);

	const std::string getName() const;
	unsigned getFacultyNumber() const;
	short getCourse() const;

	void print() const;
};

