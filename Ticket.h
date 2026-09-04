#pragma once
#include <iostream>
#include <string>

class Ticket {

protected:
    std::string showName = "";
    double price = 0;

public:
    Ticket() = default;
    Ticket(std::string name, double _price);
    void print() const;
};


class StudentTicket : public Ticket {

public:
    StudentTicket(std::string name, double _initialPrice);
};


class GroupTicket : public Ticket {

public:
    GroupTicket(std::string name, double _initialPrice);
};