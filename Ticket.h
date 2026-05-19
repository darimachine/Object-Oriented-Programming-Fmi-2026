#pragma once
#include <iostream>
#include <print>

class Ticket {
protected:
std::string name;
double price;

public:
Ticket();
Ticket(std::string name, double price);
virtual ~Ticket();

virtual double getPrice() const;

virtual void info() const;
};
