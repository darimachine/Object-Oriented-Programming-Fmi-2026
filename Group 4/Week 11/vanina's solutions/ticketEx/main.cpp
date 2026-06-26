#include <iostream>
#include "StudentTicket.h"
#include "GroupTicket.h"

int main() {
    GroupTicket group("qiwf ", 100);
    group.print();
    StudentTicket student("qiwf ", 100);
    student.print();
}