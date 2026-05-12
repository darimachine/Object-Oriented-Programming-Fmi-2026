#include "GroupTicket.h"

GroupTicket::GroupTicket(std::string name, double price) : Ticket(std::move(name), price * 0.80) { }
