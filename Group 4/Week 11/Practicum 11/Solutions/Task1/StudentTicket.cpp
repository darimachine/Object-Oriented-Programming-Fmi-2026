#include "StudentTicket.h"
StudentTicket::StudentTicket(std::string name, double price) : Ticket(std::move(name), price / 2) { }

