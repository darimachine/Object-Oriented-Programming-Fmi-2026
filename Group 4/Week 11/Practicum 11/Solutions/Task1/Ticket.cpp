#include "Ticket.h"
Ticket::Ticket(std::string name, double price)
{ 
	setName(std::move(name));
	setPrice(price);
}

double Ticket::getPrice() const
{
	return price;
}

void Ticket::setPrice(double price)
{
	if (price > 0) this->price = price;
}

const std::string& Ticket::getName() const
{
	return name;
}

void Ticket::setName(std::string name)
{
	if (!name.empty()) this->name = std::move(name);
}

void Ticket::print() const
{
	std::println("Ticket for \"{}\", costs {}$", this->getName(), this->getPrice());
}