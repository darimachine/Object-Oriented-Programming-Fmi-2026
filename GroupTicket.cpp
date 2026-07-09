#include "Ticket.h"
class GroupTicket : public Ticket {
public:
    GroupTicket(string name, double originalPrice)
        : Ticket(name, originalPrice * 0.8) {
    }

    void printInfo() {
       std::print("[Group]Ticket for: { } | Price: { } lv\n", playName, price);
    }
};
