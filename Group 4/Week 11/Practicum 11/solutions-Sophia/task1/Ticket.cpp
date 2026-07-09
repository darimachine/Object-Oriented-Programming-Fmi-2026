#include "Ticket.h"
#include <iostream>

Ticket::Ticket(const std::string& name, double price) : name(name), price(price){}

void Ticket::printInfo() const
{
    std::cout << "play name: " << name << std::endl;
    std::cout << "price: " << price << std::endl;
}

