#include "FilteredStudentDB.h"

bool FilteredStudentDB::limit(unsigned n)
{
	if (n > students.size())
	{
		return false;
	}

	students.erase(students.begin() + n);
}

void FilteredStudentDB::filter(const std::function<bool(const Student& student)>& f)
{
	erase_if(students, [&f](const Student& student)
		{
			return !f(student);
		});
}