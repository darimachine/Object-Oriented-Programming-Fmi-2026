#include "Recipient.h"

Recipient::Recipient(const string& name, const string& address)
	:name(name),address(address)
{

}

const string& Recipient::getAddress() const
{
	return address;
}

const string& Recipient::getName() const
{
	return name;
}

ostream& operator<<(ostream& os, const Recipient& r)
{
	os << r.name << r.address;
	return os;
}
