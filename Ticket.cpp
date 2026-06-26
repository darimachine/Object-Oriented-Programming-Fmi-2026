
#include <iostream>
#include <string>
#include <print>
#include "Ticket.h"


Ticket::Ticket()
{
this->name = "";
this->price = 0.0;
}

Ticket::Ticket(std::string name, double price)
: name(name), price(price) {}

Ticket::~Ticket()
{
}

double Ticket::getPrice() const
{
	return price;
}

 void Ticket::info() const
{
std::print("Ticket for {}, it costs {}\n", name, price);
}
