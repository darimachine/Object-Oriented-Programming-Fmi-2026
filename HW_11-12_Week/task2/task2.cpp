#include <iostream>
#include "StudentDB.h"
#include "StudentException.h"
#include "SortedStudentDB.h"
#include "FilteredStudentDB.h"

int main()
{
    try {
        FilteredStudentDB db;
        db.add(Student("Ivan Ivanov", 12345, 2));
        db.add(Student("Anna Petrova", 54321, 1));
        db.add(Student("Boris Kolev", 33333, 2));

        db.display();
        db.filterByYear(2);
        db.display();
        db.add(Student("Test", 11111, 10));

    }
    catch (const StudentException& e) 
    {
        std::cerr << "Validation error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}