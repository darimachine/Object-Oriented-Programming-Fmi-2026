#pragma once
#include "Ticket.h"
class StudentTicket : public Ticket
{
	private:

	public:
		StudentTicket(const std::string&, double);
		void print(std::ostream& os) const override;
};

