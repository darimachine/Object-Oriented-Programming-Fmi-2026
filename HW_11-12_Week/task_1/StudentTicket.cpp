#include "StudentTicket.h"
#include "Ticket.h"
#include <string>
#include <iostream>
StudentTicket::StudentTicket(const std::string& name, double price) : Ticket(name, price)
{

}

double StudentTicket::getPrice() const
{
	return Ticket::getPrice() / 2.0;
}

std::string StudentTicket::getType() const
{
	return "Student";
}
