#include "FilteredStudentDB.h"

FilteredStudentDB::FilteredStudentDB(std::string dbName) : StudentDB(std::move(dbName))
{ }

void FilteredStudentDB::filter(std::function<bool(const Student&)> cmp)
{
	std::erase_if(students, [cmp](const Student& s)
		{
			return !cmp(s);
		});
}

FilteredStudentDB& FilteredStudentDB::limit(size_t N)
{
	if(students.size() > N) students.resize(N);
	return *this;
}
