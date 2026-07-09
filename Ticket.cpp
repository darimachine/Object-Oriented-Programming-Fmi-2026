#include "Ticket.h"

Ticket::Ticket() : playName(" "), price(0) {}
Ticket::Ticket(string name, double p) : playName(name), price(p) {}
void Ticket::printInfo() {
    std::print("Ticket for: { } | Price: { } lv\n", playName,price);
 }
Ticket::~Ticket(){}

