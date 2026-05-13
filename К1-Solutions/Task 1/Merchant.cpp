#include "Merchant.h"

int Merchant::idCount =0;
Merchant::Merchant(const char* name, double income, double dailyRate) : id(++idCount)
{
	strcpy(this->name, name);
	this->income = income;
	this->dailyRate = dailyRate;
}

auto Merchant::operator<=>(const Merchant& other) const
{
	return income <=> other.income;
}

double Merchant::getIncome() const
{
	return income;
}

double Merchant::getId() const
{
	return id;
}

Merchant& Merchant::operator++() {
	income += dailyRate;
	return *this;
}

Merchant Merchant::operator++(int dummy) {
	Merchant temp(*this);
	++(*this);
	return temp;
}

ostream& operator<<(ostream& os, const Merchant& merchant)
{

	os << "Merchant id: " << merchant.id <<
		"Merchant name: " << merchant.name <<
		"Income: " << merchant.income <<
		"Daily Rate: " << merchant.dailyRate;
	return os;
}
