#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(int minCourse) {
    std::vector<Student> result;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getCourse() >= minCourse) {
            result.push_back(students[i]);
        }
    }
    students = result;
}

void FilteredStudentDB::limit(int n) {
    if ((int)students.size() > n) {
        students.resize(n);
    }
}