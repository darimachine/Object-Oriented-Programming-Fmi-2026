#include <iostream>
#include <vector>
#include "StudentTicket.h"
#include "GroupTicket.h"

int main() {
    GroupTicket group("a", 30);
    group.printInfo();
    std::vector<Ticket> tickets;
    tickets.push_back(StudentTicket("b", 10));
    tickets.push_back(GroupTicket("c", 20));
    for (const auto& v : tickets) {
        v.printInfo();
    }    
}