//
// Created by Vanina Laleva on 1.05.26.
//

#ifndef STUDENTS_SORTEDSTUDENTDB_H
#define STUDENTS_SORTEDSTUDENTDB_H
#include "StudentDB.h"


class SortedStudentDB : public StudentDB {
public:
    SortedStudentDB(const StudentDB& other);

    static bool compareByName(const Student& lhs, const Student& rhs);

    void sortBy(bool (*comparator) (const Student&, const Student&));
};


#endif //STUDENTS_SORTEDSTUDENTDB_H