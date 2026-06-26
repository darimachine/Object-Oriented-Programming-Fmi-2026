//
// Created by Vanina Laleva on 2.05.26.
//

#include "FilteredStudentDB.h"

FilteredStudentDB::FilteredStudentDB(const StudentDB& other) : StudentDB(other) {
}

void FilteredStudentDB::filter(bool(*shouldFilter) (const Student &)) {
    int size = students.size();

    for (int i = 0; i < size; i++) {
        if (!shouldFilter(students[i])) {
            students.erase(students.begin() + i);
        }
    }
}

void FilteredStudentDB::limit(int n) {
    int size = students.size();
    for (int i = 0; i < size - n; i++) {
        students.erase(students.end() - 1);
    }
}
