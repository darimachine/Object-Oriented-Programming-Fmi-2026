#include "FilteredStudentDB.h"
#include <vector>
#include "Student.h"
#include "StudentDB.h"

void FilteredStudentDB::filterByYear(int targetYear)
{
    std::vector<Student> filtered;
    for (const auto& s : students) 
    {
        if (s.getYear() == targetYear)
        {
            filtered.push_back(s);
        }
    }
    students = filtered;
}

void FilteredStudentDB::limit(size_t n)
{
    if (n < students.size()) 
    {
        students.resize(n);
    }
}
