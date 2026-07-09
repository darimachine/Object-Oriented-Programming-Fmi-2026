#pragma once
#include"Ticket.h"

class GroupTicket:public Ticket
{
private:
	static constexpr double PERCENTAGE = 0.20;

public:
	GroupTicket(const std::string& name, double price);
};

