#include "Ticket.h"

Ticket::Ticket(const std::string& name, double price):name(name),price(price){}

std::ostream& operator<<(std::ostream& os, const Ticket& t)
{
	return os << t.name << " " << t.price << '\n';
}