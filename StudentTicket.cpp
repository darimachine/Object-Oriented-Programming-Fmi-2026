#include "StudentTicket.h"

StudentTicket::StudentTicket(std::string name, double originalPrice)
: Ticket(name, originalPrice/2.0) {}

void StudentTicket::info() const
{
	std::print("Student ticket for {}; it costs {}\n", name, price);
}
