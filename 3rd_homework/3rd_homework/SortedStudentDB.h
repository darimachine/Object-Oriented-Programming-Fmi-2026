#pragma once
#include "StudentDB.h"
#include "Criterias.h"
class SortedStudentDB : public StudentDB
{
	public:
		void sortBy(Criterias inpCroteria);
};

