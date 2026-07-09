#define _CRT_SECURE_NO_WARNINGS
#include "VehicleList.h"
#include <cstring>
#include <stdexcept>

void VehicleList::resize()
{
	unsigned newCap = cap * 2;
	Vehicle** newSlots = new Vehicle * [newCap];
	for (unsigned i = 0; i < cap; i++)
	{
		newSlots[i] = slots[i];
	}
	for (unsigned i = cap; i < newCap; i++)
	{
		newSlots[i] = nullptr;
	}
	delete[] slots;
	slots = newSlots;
	cap = newCap;
}

VehicleList::VehicleList(unsigned initialCapacity)
{
	count = 0;

	if (initialCapacity > 0)
	{
		cap = initialCapacity;
	}
	else
	{
		cap = VehicleList::CAP_SIZE;
	}

	slots = new Vehicle * [cap];

	for (unsigned i = 0; i < cap; i++)
	{
		slots[i] = nullptr;
	}
}

void VehicleList::moveFrom(VehicleList&& other) noexcept
{
	slots = other.slots;
	cap = other.cap;
	count = other.count;
	other.slots = new Vehicle * [1] { nullptr };
	other.cap = 1;
	other.count = 0;
}

void VehicleList::copyFrom(const VehicleList& other)
{
	cap = other.cap;
	count = other.count;

	slots = new Vehicle * [cap];

	for (unsigned i = 0; i < cap; i++)
	{
		if (other.slots[i])
		{
			slots[i] = new Vehicle(*other.slots[i]);
		}
		else
		{
			slots[i] = nullptr;
		}
	}
}

void VehicleList::free()
{
	for (unsigned i = 0; i < cap; i++)
	{
		delete slots[i];
	}
	delete[] slots;

	slots = nullptr;
	cap = 0;
	count = 0;
}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

VehicleList::VehicleList(VehicleList&& other) noexcept
	: slots(other.slots), cap(other.cap), count(other.count)
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

VehicleList& VehicleList::operator+=(const Vehicle& v)
{
	for (unsigned i = 0; i < cap; i++)
	{
		if (slots[i] && slots[i]->getRegistration() == v.getRegistration())
		{
			return *this;
		}
	}
	for (unsigned i = 0; i < cap; i++)
	{
		if (!slots[i])
		{
			slots[i] = new Vehicle(v);
			count++;
			return *this;
		}
	}
	resize();
	for (unsigned i = 0; i < cap; i++)
	{
		if (!slots[i])
		{
			slots[i] = new Vehicle(v);
			count++;
			return *this;
		}
	}
	return *this;
}

VehicleList& VehicleList::operator-=(const Registration& reg)
{
	for (unsigned i = 0; i < cap; i++)
	{
		if (slots[i] && slots[i]->getRegistration() == reg)
		{
			delete slots[i];
			slots[i] = nullptr;
			count--;
			return *this;
		}
	}
	return *this;
}

unsigned VehicleList::operator()(const char* cityCode) const
{
	if (!cityCode)
	{
		return 0;
	}

	unsigned result = 0;
	char city[4] = {};

	for (unsigned i = 0; i < cap; i++)
	{
		if (!slots[i])
		{
			continue;
		}
		slots[i]->getRegistration().getCity(city);
		if (strcmp(city, cityCode) == 0)
		{
			result++;
		}
	}
	return result;
}

Vehicle* VehicleList::operator[](unsigned index)
{
	if (index >= cap)
	{
		return nullptr;
	}
	return slots[index];
}

const Vehicle* VehicleList::operator[](unsigned index) const
{
	if (index >= cap)
	{
		return nullptr;
	}
	return slots[index];
}

std::partial_ordering VehicleList::operator<=>(const VehicleList& other) const
{
	if (count != other.count)
	{
		return count <=> other.count;
	}
	const char* a = nullptr;
	const char* b = nullptr;
	for (unsigned i = 0; i < cap; i++)
	{
		if (slots[i])
		{
			a = slots[i]->getRegistration().toString();
			break;
		}
	}
	for (unsigned i = 0; i < other.cap; i++)
	{
		if (other.slots[i])
		{
			b = other.slots[i]->getRegistration().toString();
			break;
		}
	}
	if (!a && !b)
	{
		return std::partial_ordering::equivalent;
	}
	if (!a)
	{
		return std::partial_ordering::less;
	}
	if (!b)
	{
		return std::partial_ordering::greater;
	}
	int compare = strcmp(a, b);
	if (compare < 0)
	{
		return std::partial_ordering::less;
	}
	if (compare > 0)
	{
		return std::partial_ordering::greater;
	}
	return std::partial_ordering::equivalent;
}

bool VehicleList::operator==(const VehicleList& other) const
{
	return (count == other.count);
}

VehicleList::operator bool() const
{
	return count > 0;
}

bool VehicleList::isFreeSlot(unsigned pos) const
{
	if (pos >= cap)
	{
		return false;
	}
	return (slots[pos] == nullptr);
}
bool VehicleList::isEmpty() const
{
	return count == 0;
}
unsigned VehicleList::capacity() const
{
	return cap;
}
unsigned VehicleList::size() const
{
	return count;
}

Vehicle* VehicleList::find(const Registration& reg) const
{
	for (unsigned i = 0; i < cap; i++)
	{
		if (slots[i] && slots[i]->getRegistration() == reg)
		{
			return slots[i];
		}
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list)
{
	for (unsigned i = 0; i < list.cap; i++)
	{
		if (list.slots[i])
		{
			os << list.slots[i]->getRegistration() << " ";
		}
		else
		{
			os << "[*] ";
		}
	}
	return os;
}