#pragma once
#include "Ticket.h"
class StudentTicket : public Ticket
{
public:
	StudentTicket(const std::string& name, double price);
	double getPrice() const override;
	std::string getType() const override;
};

