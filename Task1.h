#pragma once
#include <string>

class Ticket {
protected:
	std::string nameOfProduction;
	double price;

public:
	Ticket(const std::string&, double);
	virtual void print() const;
	virtual ~Ticket() = default;
};

class StudentTicket : public Ticket {
public:
	StudentTicket(const std::string&, double);
	void print() const override;
};

class GroupTicket : public Ticket {
public:
	GroupTicket(const std::string&, double);
	void print() const override;
};