#include <iostream>
#include "Student.h"
#include "StudentDB.h"
#include "SortedStudentDB.h"
#include "FilteredStudentDB.h"


int main()
{
    Student s1("Ivan", 2), 
        s2("Maria", 4), 
        s3("Georgi", 1), 
        s4("Anna", 3);

    std::cout << "--- Base DB Test ---\n";
    StudentDB db;
    db.add(s1);
    db.add(s2); 
    db.add(s3);
    db.display();

    std::cout << "\n--- Search & Remove Test ---\n";
    try {
        db.find(s2.getFacultyNumber()).print();
    }
    catch (const char* msg) {
        std::cout << msg << "\n";
    }
    db.remove(s1.getFacultyNumber());
    db.display();

    std::cout << "\n--- Sorting Test (Descending) ---\n";
    SortedStudentDB sortedDb;
    sortedDb.add(s1); 
    sortedDb.add(s2); 
    sortedDb.add(s3); 
    sortedDb.add(s4);

    sortedDb.sortBy(Criteria::course);
    sortedDb.display();

    std::cout << "\n--- Filtering Test (Course >= 3 & Limit 1) ---\n";
    FilteredStudentDB filteredDb;
    filteredDb.add(s1); 
    filteredDb.add(s2); 
    filteredDb.add(s3); 
    filteredDb.add(s4);

    filteredDb.filter([](const Student& s) { return s.getCourse() >= 3; });
    filteredDb.limit(1);
    filteredDb.display();

    return 0;
}

