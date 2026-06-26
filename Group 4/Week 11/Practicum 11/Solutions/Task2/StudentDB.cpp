#include "StudentDB.h"

StudentDB::StudentDB(std::string dbName)
{
	setName(std::move(dbName));
}

const std::string& StudentDB::getName() const
{
	return dbName;
}

void StudentDB::setName(std::string dbName)
{
	if (!dbName.empty()) this->dbName = dbName;
}

void StudentDB::add(const Student& student)
{
	students.emplace_back(student);
}

void StudentDB::remove(unsigned facultyNumber)
{
	std::erase_if(students, [facultyNumber](const Student& student)
		{
			return student.getFacultyNumber() == facultyNumber;
		});
}

const Student* StudentDB::find(unsigned facultyNumber) const
{
	auto it = std::find_if(students.begin(), students.end(), [facultyNumber](const Student& student)
		{
			return student.getFacultyNumber() == facultyNumber;
		});
	if (it != students.end()) return &(*it);
	return nullptr;
}

void StudentDB::display() const
{
	std::println("Database Name: {}", dbName);
	for (const auto& s : students)
	{
		std::println("Name: {}\nFaculty Number: {}\nCourse: {}",s.getName(), s.getFacultyNumber(), s.getCourse());
	}
}
