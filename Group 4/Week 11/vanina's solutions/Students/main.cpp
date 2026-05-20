#include <iostream>

#include "FilteredStudentDB.h"
#include "SortedStudentDB.h"
#include "StudentDB.h"

int main() {
    StudentDB db;
    Student st1("Ivan Ivanov", 2975, 5);
    Student st2("Ivan Georgiev", 5942, 1);
    Student st3("Georgi Ivanov", 2956, 2);
    Student st4("Georgi Georgiev", 1085, 3);
    Student st5("Slavi Ivanov", 1050, 4);
    Student st6("Stefani Georgieva", 1863, 5);
    db.add(st1);
    db.add(st2);
    db.add(st3);
    db.add(st4);
    db.add(st5);
    db.add(st6);

    db.display();

    db.remove(2975);
    std::cout << "========= new data =======\n";
    db.display();

    if (db.find(2956)) {
        std::cout << "2956 is in DB\n";
    }
    else {
        std::cout << "2956 isn't in DB\n";
    }

    SortedStudentDB db2(db);
    std::cout << "\n======== new data base =======\n";
    db2.display();

    db2.sortBy(db2.compareByName);
    std::cout << "\n======== after sorting =======\n";
    db2.display();

    FilteredStudentDB db3(db);
    // db3.filter([] (const Student& s) {return s.getCourse() == 5; });
    std::cout << "\n======== after filtering =======\n";
    db3.display();

    db3.limit(10);
    std::cout << "\n======== after limit =======\n";
    db3.display();
}
