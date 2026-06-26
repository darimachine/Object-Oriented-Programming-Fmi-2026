#pragma once
#include "SortedStudentDB.h"
#include "FIlterCriterias.h"
class FilterStudentDB : public SortedStudentDB
{
	public:
		void filter(FilterCriterias inpCriteria, unsigned inpCourse);
		void filter(FilterCriterias inpCriteria, const std::string& inpName);
		void limit(unsigned countStudents);
};

