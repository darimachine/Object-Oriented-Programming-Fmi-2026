#include "StudentTicket.h"

StudentTicket::StudentTicket(const std::string& name, double studentPrice) : Ticket(name, studentPrice/2.0) {}
