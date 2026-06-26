#include "StudentDB.h"
#include <algorithm>
#include <iostream>

void StudentDB::add(const Student& student)
{
    auto it = std::find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getFacultyNumber() == student.getFacultyNumber();
        });

    if (it != students.end())
    {
        std::cout << "Student: " << student.getName() << " already exists.";
        return;
    }

    students.push_back(student);
}

void StudentDB::remove(const unsigned facultyNumber)
{
    auto it = std::find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getFacultyNumber() == facultyNumber;
        });

    if (it == students.end())
    {
        std::cout << "Student with facuty number: " << facultyNumber << " does not exists.";
        return;
    }

    students.erase(it);
}

Student& StudentDB::find(unsigned facultyNumber)
{
    auto it = std::find_if(students.begin(), students.end(),
        [&](const Student& s) {
            return s.getFacultyNumber() == facultyNumber;
        });

    if (it == students.end())
    {
        throw "No such student";
    }

    return *it;
}

void StudentDB::display()
{
    std::cout << "=== StudentDB (" << students.size() << " students) ===\n";
    if (students.empty()) {
        std::cout << "Database is empty.\n";
        return;
    }

    for (const auto& s : students)
        s.print();
}
