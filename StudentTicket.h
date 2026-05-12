#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket {
public:
    StudentTicket(string name, double originalPrice);
    void printInfo() override;
};
