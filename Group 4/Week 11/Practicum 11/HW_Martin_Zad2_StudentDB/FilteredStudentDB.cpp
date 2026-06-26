#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(std::function<bool(const Student&)> criteria)
{
	auto it = std::remove_if(students.begin(), students.end(), [criteria](const Student& s) {
		return !criteria(s);
	});

	students.erase(it, students.end());
}

void FilteredStudentDB::limit(unsigned N)
{
	if (students.size() > N)
	{
		students.resize(N);
	}
}
