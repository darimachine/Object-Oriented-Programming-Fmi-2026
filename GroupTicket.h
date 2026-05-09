#pragma once
#include "Ticket.h"

class GroupTicket : Ticket {
public:
	GroupTicket(std::string name, double originalPrice);

	virtual void info() const;

};
