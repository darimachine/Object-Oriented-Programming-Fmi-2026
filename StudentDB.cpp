#include "StudentDB.h"

bool StudentDB::add(const Student& student)
{
	auto it = find_if(students.begin(), students.end(), [&student](const Student& s)
		{
			return student.getId() == s.getId();
		});

	if (it != students.end())
	{
		return false;
	}

	students.push_back(student);
	return true;
}

bool StudentDB::remove(unsigned id)
{
	size_t oldSize = students.size();
	std::erase_if(students, [&id](const Student& student)
		{
			return student.getId() == id;
		});

	if (oldSize != students.size())
	{
		return true;
	}
	return false;
}

const Student& StudentDB::find(unsigned id)const
{
	auto it = find_if(students.begin(), students.end(), [&id](const Student& s)
		{
			return id == s.getId();
		});

	if (it == students.end())
	{
		throw std::runtime_error("Student is not found.");
	}
	return *it;
}

void StudentDB::display()const
{
	for (const auto& student : students)
	{
		cout << student;
	}
}