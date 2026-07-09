
#include "StudentTicket.h"

StudentTicket::StudentTicket(string name, double originalPrice)
    : Ticket(name, originalPrice / 2) {
}

void StudentTicket::printInfo()  {
  std::print("[Student]Ticket for: { } | Price: { } lv\n", playName, price);
}
