#pragma once
#include "StudentDB.h"
#include <functional>

class FilteredStudentDB :
    public StudentDB
{
public:
    void filter(std::function<bool(const Student&)> criteria);
    void limit(unsigned N);
};

