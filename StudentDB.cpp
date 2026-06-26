#include "StudentDB.h"

void StudentDB::addStudent(const Student& student)
{
students.push_back(student);
}

void StudentDB::removeStudent(unsigned int facultyNum)
{
	auto it = std::remove_if(students.begin(), students.end(), [facultyNum](const Student& s) {
		return s.id == facultyNum;
	});
	students.erase(it, students.end());
}

Student* StudentDB::findStudent(unsigned int id)
{
	for (auto& s : students) {
		if (s.id == id) return &s;
	}
	return nullptr;
}

void StudentDB::display() const
{
	if (students.empty()) {
	std::print("No students in the database.\n");
	return;
	}

	for (const auto& s : students) {
		s.print();
	}
}
