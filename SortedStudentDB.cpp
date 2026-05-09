#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(std::function<bool(const Student&, const Student&)> criterion) {
    std::sort(students.begin(), students.end(), criterion);
}
