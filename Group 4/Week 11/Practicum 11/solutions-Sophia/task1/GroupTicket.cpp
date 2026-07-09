#include "GroupTicket.h"

GroupTicket::GroupTicket(const std::string& name, double groupPrice) : Ticket(name, groupPrice*0.8) {}