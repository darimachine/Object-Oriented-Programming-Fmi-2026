#pragma once
#include "Ticket.h"
class GroupTicket : public Ticket
{
	private:

	public:
		GroupTicket(const std::string& inpName, double inpPrice);

		void print(std::ostream& os) const override;
};

