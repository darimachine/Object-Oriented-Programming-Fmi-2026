//
// Created by Vanina Laleva on 29.04.26.
//

#ifndef TICKETEX_STUDENTTICKET_H
#define TICKETEX_STUDENTTICKET_H
#include "Ticket.h"


class StudentTicket : public Ticket {
public:
    StudentTicket(const std::string& name, double price);
};


#endif //TICKETEX_STUDENTTICKET_H