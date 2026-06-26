#include <iostream>
#include "Ticket.h"

Ticket::Ticket(std::string name, double _price)
{
    showName = name;
    price = _price;
}

void Ticket::print() const
{
    std::cout << "Show: " << showName << std::endl;
    std::cout << "Price: " << price << std::endl;
}

StudentTicket::StudentTicket(std::string name, double _initialPrice) : Ticket(name, _initialPrice/2) {}

GroupTicket::GroupTicket(std::string name, double _initialPrice) : Ticket(name, _initialPrice * 80 / 100) {}