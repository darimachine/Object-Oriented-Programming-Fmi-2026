#pragma once
#include <string>
#include <print>
class Ticket
{
	std::string name = "Unknown";
	double price = 0;
public:
	Ticket(std::string name, double price);
	double getPrice() const;
	void setPrice(double price);
	const std::string& getName() const;
	void setName(std::string name);

	void print() const;
};

