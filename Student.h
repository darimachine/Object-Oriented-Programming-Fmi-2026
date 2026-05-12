#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <string>

class Student {
	std::string name = "";
	unsigned facultyNumber;
	static unsigned id;
	unsigned course;

public:
	Student(std::string _name, unsigned _course);
	std::string getName() const;
	unsigned getCourse() const;
	unsigned getFNum() const;
	unsigned getId() const;
};
unsigned Student::id = 0;


class StudentDB {
protected:
	std::vector<Student> vStudents;

public:
	void add(const Student& s);
	void remove(unsigned fn);
	const Student& find(unsigned facultyNum) const;
	void display() const;
};


class SortedStudentDB : public StudentDB {
public:
	void sortBy(std::function<bool(const Student&, const Student&)> comp);
};


class FilteredStudentDB : public StudentDB {
public:
	void filter(std::function<bool(const Student&)> predicate);
	void limit(int N);
};