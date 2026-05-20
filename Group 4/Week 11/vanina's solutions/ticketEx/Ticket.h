//
// Created by Vanina Laleva on 29.04.26.
//

#ifndef TICKETEX_TICKET_H
#define TICKETEX_TICKET_H

#include <iostream>
#include <string>


class Ticket {
    std::string name;
    double price;

public:
    Ticket(const std::string& name, double price);
    void print() const;
};


#endif //TICKETEX_TICKET_H