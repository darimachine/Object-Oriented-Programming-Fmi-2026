#pragma once
#include "Student.h"
#include <vector>

class StudentDB
{
	std::string dbName = "Unknown";

protected:
	std::vector<Student> students;

public:
	StudentDB(std::string dbName = "Unnamed");

	const std::string& getName() const;
	void setName(std::string dbName);

	void add(const Student& student);
	void remove(unsigned facultyNumber);
	const Student* find(unsigned facultyNumber) const;
	void display() const;
};

