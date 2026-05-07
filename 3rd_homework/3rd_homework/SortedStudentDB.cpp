#include "SortedStudentDB.h"
#include <algorithm>
void SortedStudentDB::sortBy(Criterias inpCroteria)
{
	switch (inpCroteria)
	{
	case Criterias::ByName:
		std::sort(currentStudents.begin(), currentStudents.end(), [](const Student& a, const Student& b)
			{return a.getName() < b.getName(); });
		break;

	case Criterias::ByCourse:
		std::sort(currentStudents.begin(), currentStudents.end(), [](const Student& a, const Student& b)
			{return a.getCourse() < b.getCourse(); });
		break;

	case Criterias::ByID:
		std::sort(currentStudents.begin(), currentStudents.end(), [](const Student& a, const Student& b)
			{return a.getPersonalID() < b.getPersonalID(); });
		break;
	}
}
