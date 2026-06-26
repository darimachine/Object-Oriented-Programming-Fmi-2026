#pragma once
#include <string>
#include <iostream>
constexpr double MIN_PRICE = 0;
class Ticket
{
	private:
		std::string name;
		double price;

		void setPrice(double);
	public:
		Ticket(const std::string&, double);

		virtual ~Ticket() = default;

		friend std::ostream& operator<<(std::ostream& os, const Ticket& obj);
		virtual void print(std::ostream&) const;
		

};

