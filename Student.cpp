#include <iostream>
#include <algorithm>
#include "Student.h"

Student::Student(std::string _name, unsigned _course):name(_name), course(_course)
{
	facultyNumber = ++id;
}

std::string Student::getName() const
{
	return name;
}

unsigned Student::getCourse() const
{
	return course;
}

unsigned Student::getFNum() const
{
	return facultyNumber;
}

void StudentDB::add(const Student& s)
{
	if (s.getName().size() >= 2 && s.getCourse()>0 && s.getCourse() < 5) {
		vStudents.push_back(s);
	}
}

void StudentDB::remove(unsigned fn)
{
		std::erase_if(vStudents, [fn](const Student& x) { return x.getFNum() == fn; });
}

const Student& StudentDB::find(unsigned facultyNum) const
{
	for (const auto& x : vStudents) {
		if (x.getFNum() == facultyNum)
			return x;
	}
	throw std::runtime_error("Student not found!");
}

void StudentDB::display() const
{
	for (const auto& x : vStudents) {
		std::cout << x.getName() << " - faculty number " << x.getFNum() << ", course " << x.getCourse()<<std::endl;
	}
}

void FilteredStudentDB::filter(std::function<bool(const Student&)> predicate)
{
	std::erase_if(vStudents, [&predicate](const Student& s){ return !predicate(s);});
}

void FilteredStudentDB::limit(int N)
{
	if (N <= vStudents.size())
		vStudents.erase(vStudents.begin()+N, vStudents.end());
}

void SortedStudentDB::sortBy(std::function<bool(const Student&, const Student&)> comp)
{
	std::sort(vStudents.begin(), vStudents.end(), comp);
}


int main()
{
}