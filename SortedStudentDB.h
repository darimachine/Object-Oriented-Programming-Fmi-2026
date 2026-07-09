#pragma once
#include "StudentDB.h"

class SortedStudentDB : public StudentDB {
public:
    void sortBy(std::string criterion);
};