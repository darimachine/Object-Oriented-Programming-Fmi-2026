#include "Ticket.h"
#include <iostream>
using namespace std;
void Ticket::setPrice(double inpPrice)
{
	if (inpPrice < MIN_PRICE)
	{
		throw std::invalid_argument("Ticket price can not be a negative number");
	}
	else
	{
		price = inpPrice;
	}
}

Ticket::Ticket(const string& inpName, double inpPrice): name(inpName)
{
	setPrice(inpPrice);
}

void Ticket::print(ostream& os) const
{
	os << "Play: " << name << " ticket price: " << price << '\n';
}

ostream& operator<<(ostream& os, const Ticket& obj)
{
	obj.print(os);
	return os;
}
