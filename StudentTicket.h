#pragma once
#include "Ticket.h"

class StudentTicket : Ticket {
	public:
	StudentTicket(std::string name, double price);

	virtual void info() const;

};
