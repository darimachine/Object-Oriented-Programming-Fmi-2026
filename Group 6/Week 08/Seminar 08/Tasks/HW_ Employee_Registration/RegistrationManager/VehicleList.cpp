#include "VehicleList.h"

void VehicleList::resize()
{
	int newCap = capacity * 2;

	Vehicle** newSlots = new Vehicle * [newCap];
	for (size_t i = 0; i < capacity; i++)
	{
		newSlots[i] = slots[i];
	}
	for (size_t i = capacity; i < newCap; i++)
	{
		newSlots[i] = nullptr;
	}

	delete[] slots;
	slots = newSlots;
	capacity = newCap;
}

int VehicleList::findIndex(const Registration& reg)
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] != nullptr && slots[i]->getRegistration() == reg)
			return i;
	}

	return -1;
}

VehicleList::VehicleList(const int initialCapacity) : capacity(initialCapacity)
{
	if (capacity <= 0)
		throw std::invalid_argument("Invalid input.");

	slots = new Vehicle*[initialCapacity];
	for (size_t i = 0; i < capacity; i++)
	{
		slots[i] = nullptr;
	}
}

VehicleList& VehicleList::operator+=(const Vehicle& v)
{
	if (count == capacity)
		resize();

	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] != nullptr && slots[i]->getRegistration() == v.getRegistration())
			return *this;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = new Vehicle(v);
			count++;
			return *this;
		}
	}

	resize();
	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] == nullptr)
		{
			slots[i] = new Vehicle(v);
			count++;
			return *this;
		}
	}

	return *this;
}

VehicleList& VehicleList::operator-=(const Registration& r)
{
	if (!r)
		return *this;

	int index = findIndex(r);
	if (index != -1)
	{
		delete slots[index];
		slots[index] = nullptr;
		count--;
	}

	return *this;
}

int VehicleList::operator()(const char* city)
{
	int counter = 0;

	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] != nullptr &&
			std::strcmp(slots[i]->getRegistration().getCityCode(), city) == 0)
		{
			counter++;
		}
	}

	return counter;
}

VehicleList::operator bool() const
{
	if (count == 0)
		return false;

	return true;
}

const Vehicle& VehicleList::operator[](int index) const
{
	return *slots[index];	
}

Vehicle& VehicleList::operator[](int index)
{
	return *slots[index];
}

bool VehicleList::isFreeSlot(int pos) const
{
	return slots[pos] == nullptr;
}

bool VehicleList::isEmpty() const
{
	if (count == 0)
		return true;

	return false;
}

Vehicle* VehicleList::find(const Registration& reg) const
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (slots[i] != nullptr && slots[i]->getRegistration() == reg)
		{
			return slots[i];
		}
	}

	return nullptr;
}

std::strong_ordering VehicleList::operator<=>(const VehicleList& other) const
{
	if (auto cmp = count <=> other.count; cmp != 0)
	{
		return cmp;
	}

	if (slots[0] != 0)
	{
		if (other.slots[0] != 0)
		{
			return slots[0]->getRegistration() <=> other.slots[0]->getRegistration();
		}

		return std::strong_ordering::greater;
	}
	else
	{
		if (other.slots[0] != 0)
			return std::strong_ordering::less;
	}

	return std::strong_ordering::equivalent;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& v)
{
	os << "Vehicle list: \n";
	os << "------------------------------\n";

	for (size_t i = 0; i < v.capacity; i++)
	{
		if (v.slots[i] == nullptr)
		{
			os << "-*-";
		}
		else
		{
			os << *v.slots[i];
		}
	}

	return os;
}
