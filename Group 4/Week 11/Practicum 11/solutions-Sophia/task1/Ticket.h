#pragma once
#include <string>

class Ticket {
    protected:
        std::string name;
        double price;
    public:
        Ticket(const std::string& name, double price);
        void printInfo() const;
};