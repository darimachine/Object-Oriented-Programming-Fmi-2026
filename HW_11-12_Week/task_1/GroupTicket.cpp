#include "GroupTicket.h"
#include "Ticket.h"

GroupTicket::GroupTicket(const std::string& name, double price) : Ticket(name, price)
{
}

double GroupTicket::getPrice() const 
{
    return Ticket::getPrice() * 0.80; 
}

std::string GroupTicket::getType() const
{
    return "Group";
}