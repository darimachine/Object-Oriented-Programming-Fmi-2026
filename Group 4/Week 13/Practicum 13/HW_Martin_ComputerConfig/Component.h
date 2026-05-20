#pragma once
#include <string>
#include <iostream>

class Component
{
private:
	std::string ticket;
	
public:
	Component(const std::string& ticket);

	virtual std::unique_ptr<Component> clone() const = 0;

	virtual ~Component() = default;

	virtual double price() const = 0; //returns the price

	virtual void output(std::ostream& os) const = 0;

	const std::string getTicket() const;
};

