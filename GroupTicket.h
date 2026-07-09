#pragma once
#include "Ticket.h"
class GroupTicket : public Ticket {
public:
    GroupTicket(string name, double originalPrice);
    void printInfo() override;
}
