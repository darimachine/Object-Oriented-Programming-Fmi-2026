#include "GroupTicket.h"
using namespace std;
constexpr double procentForPromo = 0.8;
#include <iostream>
GroupTicket::GroupTicket(const string& inpName, double inpPrice) : Ticket(inpName, inpPrice* procentForPromo)
{
}

void GroupTicket::print(ostream& os) const
{
	os << "Group ticket: ";
	Ticket::print(os);
}
