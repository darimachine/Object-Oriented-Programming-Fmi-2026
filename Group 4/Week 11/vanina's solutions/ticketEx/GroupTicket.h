//
// Created by Vanina Laleva on 29.04.26.
//

#ifndef TICKETEX_GROUPTICKET_H
#define TICKETEX_GROUPTICKET_H
#include "Ticket.h"


class GroupTicket : public Ticket {
public:
    GroupTicket(const std::string& name, double price);
};


#endif //TICKETEX_GROUPTICKET_H