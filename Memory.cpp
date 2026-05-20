#include "Memory.h"
#include<stdexcept>

Memory::Memory(const string& label, unsigned short capacity):Component(label)
{
	if (capacity < 1 || capacity>10000)
	{
		throw logic_error("Capacity must be between 1 and 1000.");
	}
	this->capacity = capacity;
}

double Memory::price()const
{
	return MEMORY_PRICE * capacity;
}

void Memory::output(std::ostream& os)const
{
	os << getLabel() << " " << MEMORY_PRICE << " " << capacity << '\n';
}

unique_ptr<Component> Memory::clone()const
{
	return make_unique<Memory>(getLabel(), capacity);
}