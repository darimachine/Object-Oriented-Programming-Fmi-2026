#include "FilterStudentDB.h"
#include <stdexcept>
#include <algorithm>
void FilterStudentDB::filter(FilterCriterias inpCriteria, unsigned inpCourse)
{
	if (inpCourse > MAX_COURSE)
	{
		throw std::invalid_argument("The inputed course is invalid");
	}
	if (inpCriteria == FilterCriterias::byCourse)
	{
		std::erase_if(currentStudents, [inpCourse](const Student& currS)
			{return currS.getCourse() != inpCourse; });
	}
}

void FilterStudentDB::filter(FilterCriterias inpCriteria, const std::string& inpName)
{
	if (inpCriteria == FilterCriterias::byName)
	{
		std::erase_if(currentStudents, [inpName](const Student& currS)
			{return inpName != currS.getName(); });
	}
}

void FilterStudentDB::limit(unsigned countStudents)
{
	if (countStudents < currentStudents.size())
	{
		currentStudents.resize(countStudents);
	}
}
