#include "Ticket.h"

Ticket::Ticket(std::string _staging, double _price)
{
	if (staging != _staging) {
		staging = _staging;
	}
	if (_price > 0) {
		price = _price;
	}
}

void Ticket::print() const
{
	std::cout << "Staging name: " << staging << std::endl;
	std::cout << "Price: " << price << std::endl;
}

double Ticket::getPrice() const
{
	return price;
}

Ticket::~Ticket()
{

}

StudentTicket::StudentTicket(std::string _staging, double original_price) 
	: Ticket(_staging, original_price/2) {
}

void StudentTicket::print() const
{
	std::cout << "Staging name: " << staging << std::endl;
	std::cout << "Type: student \n";
	std::cout << "Price: " << getPrice() << std::endl;
}

double StudentTicket::getPrice() const
{
	return price;
}

GroupTicket::GroupTicket(std::string _staging, double original_price)
	: Ticket(_staging, original_price*0.8)
{
}

void GroupTicket::print() const
{
	std::cout << "Staging name: " << staging << std::endl;
	std::cout << "Type: group \n";
	std::cout << "Price: " << getPrice() << std::endl;
}
