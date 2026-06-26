#include <iostream>
#include <vector>

#include "Ticket.h"
#include "StudentTicket.h"
#include "GroupTicket.h"

int main()
{
    Ticket regular("film 1", 100.0);
    regular.print();

    std::string studentName = "film 2";
    StudentTicket student(std::move(studentName), 100.0);
    student.print();

    GroupTicket group("film 3", 100.0);
    group.print();

    return 0;
}