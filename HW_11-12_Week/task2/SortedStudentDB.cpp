#include "SortedStudentDB.h"

void SortedStudentDB::sortByName()
{
	if (students.size() < 2)
	{
		return;
	}

	for (size_t i = 0; i < students.size() - 1; ++i)
	{
		for (size_t j = 0; j < students.size() - i - 1; ++j) 
		{
			if (students[j].getName() > students[j + 1].getName())
			{
				std::swap(students[j], students[j + 1]);
			}
		}
	}
}
