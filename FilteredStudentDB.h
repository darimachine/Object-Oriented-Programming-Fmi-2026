#pragma once
#include "StudentDB.h"

class FilteredStudentDB : public StudentDB {
public:
    void filter(int minCourse);
    void limit(int n);
};