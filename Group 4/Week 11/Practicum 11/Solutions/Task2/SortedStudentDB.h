#pragma once
#include "StudentDB.h"
#include <algorithm>
#include <functional>
class SortedStudentDB : public StudentDB
{
public:
	SortedStudentDB(std::string dbName = "Unnamed");

	void sortBy(std::function<bool(const Student&, const Student&)> cmp);
};

