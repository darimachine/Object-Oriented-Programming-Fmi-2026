#pragma once
#include "Student.h"
#include <vector>
class StudentDB		
{
	protected:
		std::vector<Student> currentStudents;
	public:
		void add(const Student& joiningStudent);
		void remove(unsigned inpID);
		bool find(unsigned inpID) const;
		void display() const;
};

