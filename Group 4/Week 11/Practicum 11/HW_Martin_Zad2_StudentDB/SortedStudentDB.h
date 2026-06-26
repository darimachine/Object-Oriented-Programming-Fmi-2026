#pragma once
#include "StudentDB.h"
#include <algorithm>

enum class Criteria
{
	name,
	faciltyNumber,
	course
};

class SortedStudentDB : public StudentDB
{
public:
	void sortBy(Criteria criteria);
};

