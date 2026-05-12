#pragma once
#include <iostream>
#include <string>
#include <print>
using std::string;

class Ticket {
protected:
    string playName;
    double price;

public:
    Ticket();
    Ticket(string name, double p);
    virtual void printInfo();
    virtual ~Ticket();
};
