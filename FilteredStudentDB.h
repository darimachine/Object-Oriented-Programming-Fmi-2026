#pragma once
#include"StudentDB.h"
#include<functional>

class FilteredStudentDB: public StudentDB
{
	bool limit(unsigned n);
	void filter(const std::function<bool(const Student& student)>& f);
};

