//
// Created by Vanina Laleva on 2.05.26.
//

#ifndef STUDENTS_FILTEREDSTUDENTDB_H
#define STUDENTS_FILTEREDSTUDENTDB_H
#include "StudentDB.h"


class FilteredStudentDB : public StudentDB {
public:
    explicit FilteredStudentDB(const StudentDB& other);

    void filter(bool (*shouldFilter) (const Student&));
    void limit(int n);
};


#endif //STUDENTS_FILTEREDSTUDENTDB_H