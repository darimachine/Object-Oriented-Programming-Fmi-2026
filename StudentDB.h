#pragma once
#include "Student.h"
#include <algorithm>
#include <vector>

class StudentDB{
	protected:
		std::vector<Student> students;

	public:

	virtual ~StudentDB() = default;

	void addStudent(const Student& student);

	void removeStudent(unsigned int facultyNum);

	Student* findStudent(unsigned int id);

	virtual void display() const;
};
