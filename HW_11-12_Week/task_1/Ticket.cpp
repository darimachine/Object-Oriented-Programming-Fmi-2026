#include "Ticket.h"
#include "InvalidTicketException.h"
#include <iostream>

const double Ticket::MIN_PRICE = 0.99;

void Ticket::validateName(const std::string& name)
{
	if (name.empty())
	{
		throw InvalidTicketException("Name cannot be empty!");
	}
}

void Ticket::validatePrice(double price)
{
	if (price < MIN_PRICE)
	{
		throw InvalidTicketException("Price must be at least 0.99");
	}
}

Ticket::Ticket(const std::string& name, double price)
{
	validateName(name);
	validatePrice(price);
	this->name = name;
	this->price = price;
}

std::string Ticket::getType() const
{
	return "Standard";
}

const std::string& Ticket::getName() const
{
	return name;
}

double Ticket::getPrice() const
{
	return price;
}

std::ostream& operator<<(std::ostream& os, const Ticket& t)
{
	os << "Production: " << t.getName() << std::endl;
	os << "Category: " << t.getType() << std::endl;
	os << "Final Price: " << t.getPrice() << " EURO" << std::endl;
	return os;
}
