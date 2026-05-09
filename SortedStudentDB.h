#pragma once
#include  "StudentDB.h"
#include  "Student.h"
#include <functional>

class SortedStudentDB : public StudentDB {
public:
void sortBy(std::function<bool(const Student&, const Student&)> criterion);
};
