#include "GroupTicket.h"
#include <print>

double PERCENT = 0.8;
GroupTicket::GroupTicket(std::string name, double originalPrice)
	: Ticket(name, originalPrice*PERCENT) {}

void GroupTicket::info() const
{
	std::print("Group ticket for {}; it costs {}\n", name, price);
}
