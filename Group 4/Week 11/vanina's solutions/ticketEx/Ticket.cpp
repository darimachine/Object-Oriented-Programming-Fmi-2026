//
// Created by Vanina Laleva on 29.04.26.
//

#include "Ticket.h"

Ticket::Ticket(const std::string &name, double price) : name(name), price(price) { }

void Ticket::print() const {
    std::cout << "\"" << name << "\" - " << price << "\n";
}

