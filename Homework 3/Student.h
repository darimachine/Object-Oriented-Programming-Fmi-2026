#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
class Student
{
protected:
	std::string name;
	std::unique_ptr<unsigned> number;
	unsigned int course;
public:
	Student(std::string _name, unsigned _number, unsigned int _course);
	Student();
	unsigned getNumber() const;
	void const print() const;
	std::string getName() const;
	unsigned int getCourse() const;

};

class StudentBD : public Student {
protected:
	std::vector<std::unique_ptr<Student>> stdtBD;
public:
	StudentBD();
	void add(std::string _name, unsigned _number, unsigned int _course);
	void remove(std::unique_ptr<unsigned> _number);
	bool find(std::unique_ptr<unsigned> _number);
	void display() const;
};

class SortedStudentBD : public StudentBD {
public:
	void sortBy(std::string srt);
};

class FilteredStudentBD : public SortedStudentBD {
public:
	void filter(auto c);
	void limit(int N);
};