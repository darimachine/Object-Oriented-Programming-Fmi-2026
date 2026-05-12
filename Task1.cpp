#include "Task1.h"
#include <print>

Ticket::Ticket(const std::string& name, double _price) : nameOfProduction(name), price(_price) {}

void Ticket::print() const {
	std::println("Ticket: {}", nameOfProduction);
	std::println("Price: {} euro", price);
}

StudentTicket::StudentTicket(const std::string& name, double originalPrice) : Ticket(name, originalPrice / 2) {}

void StudentTicket::print() const {
	std::println("Student ticket: {}", nameOfProduction);
	std::println("Price with reduction: {} euro", price);
}

GroupTicket::GroupTicket(const std::string& name, double price) : Ticket(name, price * 0.8) {}

void GroupTicket::print() const {
	std::println("Group ticket: {}", nameOfProduction);
	std::println("Price with reduction: {} euro", price);
}