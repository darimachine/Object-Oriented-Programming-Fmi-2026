#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(Criteria criteria)
{
	switch (criteria)
	{
	case Criteria::name:
		std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
			return a.getName() > b.getName();
		});
		break;

	case Criteria::faciltyNumber :
		std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
			return a.getFacultyNumber() > b.getFacultyNumber();
		});
		break;

	case Criteria::course :
		std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
			return a.getCourse() > b.getCourse();
		});
		break;

	default:
		std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
			return a.getFacultyNumber() > b.getFacultyNumber();
		});
		break;
	}
}
