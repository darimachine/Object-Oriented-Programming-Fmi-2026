#include "StudentTicket.h"
#include <iostream>
using namespace std;
StudentTicket::StudentTicket(const string& inpName, double inpPrice): Ticket(inpName, inpPrice /2.0)
{

}

void StudentTicket::print(ostream& os) const
{
	os << "Student Ticket: ";
	Ticket::print(os);
}
