#pragma once
#include <string>
#include <iostream>
class Ticket
{
protected:
	std::string staging;
	double price;
public:
	Ticket(std::string _staging, double _price);
	virtual void print() const;
	virtual double getPrice() const;
	virtual ~Ticket();
};

class StudentTicket : public Ticket {
public:
	StudentTicket(std::string _staging, double original_price);
	void print() const override;
	double getPrice() const override;
};

class GroupTicket: public Ticket {
public:
	GroupTicket(std::string, double original_price);
	void print() const override;

};

