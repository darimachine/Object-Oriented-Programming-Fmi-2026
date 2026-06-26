#include "Memory.h"

Memory::Memory(const std::string& ticket, short capacity) : Component(ticket)
{
	if (capacity < 1 || capacity > 10000)
	{
		throw std::invalid_argument("Capacity is not in the boundaries.");
	}
	else
		this->capacity = capacity;
}

std::unique_ptr<Component> Memory::clone() const
{
	return std::make_unique<Memory>(*this);
}

double Memory::price() const
{
    return capacity * priceByCapacity;
}

void Memory::output(std::ostream& os) const
{
	os << "Memory, ticket: " << getTicket() << std::endl;
	os << "-------------------------" << "\n";
	os << " - price: " << price() << "\n";
	os << " - capacity: " << capacity << "\n";
}
