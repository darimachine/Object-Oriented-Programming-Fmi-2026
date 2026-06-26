#pragma once
#include "StudentDB.h"
#include <algorithm>
#include <functional>
class FilteredStudentDB : public StudentDB
{
public:
	FilteredStudentDB(std::string dbName = "Unnamed");

	void filter(std::function<bool(const Student&)> cmp);
	FilteredStudentDB& limit(size_t N);
};

