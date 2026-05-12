#include "StudentDB.h"
#include <iostream>
#include "StudentException.h"

void StudentDB::add(const Student& s)
{
	students.push_back(s);
}

void StudentDB::remove(unsigned fn)
{
	for (size_t i = 0; i < students.size(); ++i)
	{
		if (students[i].getFN() == fn)
		{
			students.erase(students.begin() + i);
			return;
		}
	}
}

Student* StudentDB::find(unsigned fn)
{
	for (size_t i = 0; i < students.size(); ++i)
	{
		if (students[i].getFN() == fn)
		{
			return &students[i];
		}
	}
	return nullptr;
}

void StudentDB::display() const
{
	if (StudentDB::students.empty())
	{
		throw StudentException("DB empty!");
	}

	for (const auto& s : students)
	{
		s.display();
	}
}
