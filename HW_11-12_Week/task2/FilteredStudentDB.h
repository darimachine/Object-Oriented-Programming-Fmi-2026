#pragma once
#include "StudentDB.h"

class FilteredStudentDB : public StudentDB
{
public:
	void filterByYear(int targetYear);
	void limit(size_t n);
};

