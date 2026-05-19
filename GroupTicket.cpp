#include "GroupTicket.h"

GroupTicket::GroupTicket(const std::string& name, double price)
	:Ticket(name,price-price*PERCENTAGE){}