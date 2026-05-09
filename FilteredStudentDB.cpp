#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(std::function<bool(const Student&)> criterion) {
    std::vector<Student> filtered;
    for (const auto& s : students) {
        if (criterion(s)) filtered.push_back(s);
    }
    students = filtered;
}

void FilteredStudentDB::limit(size_t n) {
    if (n < students.size()) students.resize(n);
}
