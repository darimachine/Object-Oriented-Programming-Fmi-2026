#pragma once
#include<string>
#include<fstream>

class Ticket
{
protected:
	std::string name;
	double price;

public:
	Ticket() = default;
	Ticket(const std::string& name, double price);

protected:
	friend std::ostream& operator<<(std::ostream& os, const Ticket& t);
};

