#pragma once
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>

class Student {
	std::string name;
	unsigned int facultyNumber;
	int year;

public:
	Student(const std::string&, unsigned int, int);
	std::string getName() const;
	unsigned int getFacultyNumber() const;
	int getYear() const;
	void print() const;
};

class StudentDB {
protected:
	std::vector<Student> students;

public:
	void add(const Student&);
	void remove(unsigned int);
	const Student* find(unsigned int) const;
	virtual void display() const;
	virtual ~StudentDB() = default;
};

enum class SortCriteria { NAME, FACULTY_NUMBER, YEAR };

class SortedStudentDB : public StudentDB {
public:
	void sortBy(SortCriteria);
	void display() const override;
};

class FilteredStudentDB : public StudentDB {
public:
	void filter(std::function<bool(const Student& s)>);
	void limit(size_t);
	void display() const override;
};