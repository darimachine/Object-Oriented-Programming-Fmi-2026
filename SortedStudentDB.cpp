#include "SortedStudentDB.h"
#include<algorithm>

void SortedStudentDB::sortBy(const std::function<bool(const Student& first, const Student& second)>& f)
{
	sort(students.begin(), students.end(), [&f](const Student& first, const Student& second)
		{
			return f(first, second);
		});
}
