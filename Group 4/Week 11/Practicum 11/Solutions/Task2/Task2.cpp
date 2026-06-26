#include <iostream>
#include "SortedStudentDB.h"
#include "FilteredStudentDB.h"

int main() {
    Student s1("Alice", 1);
    Student s2("Charlie", 3);
    Student s3("Bob", 2);
    Student s4("Diana", 2);

    std::cout << "--- Testing SortedStudentDB ---" << std::endl;
    SortedStudentDB sdb;
    sdb.add(s1);
    sdb.add(s2);
    sdb.add(s3);
    sdb.add(s4);

    std::cout << "Before sorting:" << std::endl;
    sdb.display();

    std::cout << "\nSorting by Name..." << std::endl;
    sdb.sortBy([](const Student& a, const Student& b) {
        return a.getName() < b.getName();
        });
    sdb.display();

    std::cout << "\n--- Testing FilteredStudentDB ---" << std::endl;
    FilteredStudentDB fdb;
    fdb.add(s1);
    fdb.add(s2);
    fdb.add(s3);
    fdb.add(s4);

    
    std::cout << "Filtering for Course 2 only..." << std::endl;
    fdb.filter([](const Student& s) {
        return s.getCourse() == 2;
        });
    fdb.display();

    
    std::cout << "\nLimiting to first 1 student..." << std::endl;
    fdb.limit(1);
    fdb.display();

    std::cout << "\n--- Testing Find/Remove in Base Class ---" << std::endl;
    
    StudentDB* basePtr = &sdb;
    const Student* found = basePtr->find(3);

    if (found) {
        std::cout << "Found student with FN 3: " << found->getName() << std::endl;
    }
    else {
        std::cout << "Student 3 not found." << std::endl;
    }

    std::cout << "Removing FN 3..." << std::endl;
    basePtr->remove(3);
    basePtr->display();

    return 0;
}