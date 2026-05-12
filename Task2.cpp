#include "Task2.h"
#include <print>
#include <algorithm>

Student::Student(const std::string& _name, unsigned int _fn, int _year) : name(_name), facultyNumber(_fn), year(_year) {}

std::string Student::getName() const {
	return this->name;
}

unsigned int Student::getFacultyNumber() const {
	return this->facultyNumber;
}

int Student::getYear() const {
	return this->year;
}

void Student::print() const {
	std::println("Student: {}", name);
	std::println("Faculty number: {}", facultyNumber);
	std::println("Year: {}", year);
}

void StudentDB::add(const Student& s) {
	if (find(s.getFacultyNumber()) == nullptr)
		students.push_back(s);
	else
		throw std::invalid_argument("Student with this faculty number already exists!");
}

void StudentDB::remove(unsigned int fn) {
	auto iterator = std::find_if(students.begin(), students.end(),
		[fn](const Student& s) { return fn == s.getFacultyNumber(); });
	if (iterator == students.end())
		throw std::out_of_range("Student not found!");
	students.erase(iterator);
}

const Student* StudentDB::find(unsigned int fn) const {
	for (const Student& s : students) {
		if (fn == s.getFacultyNumber())
			return &s;
	}
	return nullptr;
}

void StudentDB::display() const {
	std::println("Data base of students:");
	for (const Student& s : students) {
		s.print();
		std::println();
	}
}

void SortedStudentDB::sortBy(SortCriteria criteria) {
	auto byName = [](const Student& a, const Student& b) { return a.getName() < b.getName(); };
	auto byFN = [](const Student& a, const Student& b) { return a.getFacultyNumber() < b.getFacultyNumber(); };
	auto byYear = [](const Student& a, const Student& b) { return a.getYear() < b.getYear(); };

	switch (criteria) {
	case SortCriteria::NAME:std::sort(students.begin(), students.end(), byName);
		break;
	case SortCriteria::FACULTY_NUMBER: std::sort(students.begin(), students.end(), byFN);
		break;
	case SortCriteria::YEAR: std::sort(students.begin(), students.end(), byYear);
		break;
	}
}

void SortedStudentDB::display() const {
	std::println("Sorted data base of students:");
	for (const Student& s : students) {
		s.print();
		std::println();
	}
}

void FilteredStudentDB::filter(std::function<bool(const Student& s)> f) {
	students.erase(std::remove_if(students.begin(), students.end(),
		[f](const Student& s) { return !f(s); }), students.end());
}

void FilteredStudentDB::limit(size_t n) {
	if (n < students.size())
		students.resize(n);
}

void FilteredStudentDB::display() const {
	std::println("Filtered data base of students:");
	for (const Student& s : students) {
		s.print();
		std::println();
	}
}