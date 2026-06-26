#pragma once
#include <vector>
#include <algorithm>
#include "Student.h"

class StudentDB
{
protected:
	std::vector<Student> students;

public:
	void add(const Student& student);
	void remove(const unsigned facultyNumber);
	Student& find(unsigned facultyNumber);
	void display();
};

