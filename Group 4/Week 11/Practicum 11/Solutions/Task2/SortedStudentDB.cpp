#include "SortedStudentDB.h"

SortedStudentDB::SortedStudentDB(std::string dbName) : StudentDB(std::move(dbName))
{ }

void SortedStudentDB::sortBy(std::function<bool(const Student&, const Student&)> cmp)
{
	std::sort(students.begin(), students.end(), cmp);
}
