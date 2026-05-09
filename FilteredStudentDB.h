#pragma once
#include "StudentDB.h"
#include <functional>

class FilteredStudentDB : public StudentDB {
public:
    void filter(std::function<bool(const Student&)> criterion);
    void limit(size_t n);
};
