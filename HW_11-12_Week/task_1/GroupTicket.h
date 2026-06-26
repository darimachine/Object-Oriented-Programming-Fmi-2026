#pragma once
#include <string>
#include "Ticket.h"
class GroupTicket : public Ticket
{
public:
	GroupTicket(const std::string& name, double price);
	double getPrice() const override;
	std::string getType() const override;
};

