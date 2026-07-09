#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket {
    public: 
        GroupTicket(const std::string& name, double groupPrice);
};