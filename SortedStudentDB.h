#pragma once
#include"StudentDB.h"
#include<functional>

class SortedStudentDB:public StudentDB
{
public:
	void sortBy(const std::function<bool(const Student& first,const Student& second)>& f);
};

