#define _CRT_SECURE_NO_WARNINGS
#include "VehicleList.h"

VehicleList::VehicleList(size_t capacity) :capacity(capacity)
{
	vehicles = new Vehicle * [capacity] {nullptr};
}

void VehicleList::copyFrom(const VehicleList& other)
{
	vehicles = new Vehicle * [other.capacity] {nullptr};
	for (size_t i = 0;i < other.capacity;i++)
	{
		if (other.vehicles[i])
		{
			vehicles[i] = new Vehicle(*other.vehicles[i]);
		}
	}
	capacity = other.capacity;
	countOfVehicles = other.countOfVehicles;
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

void VehicleList::free()
{
	for (size_t i = 0;i < capacity;i++)
	{
		delete vehicles[i];
		vehicles[i] = nullptr;
	}
	delete[]vehicles;
	vehicles = nullptr;

	capacity = 0;
	countOfVehicles = 0;
}

void VehicleList::moveFrom(VehicleList&& other)
{
	vehicles = other.vehicles;
	capacity = other.capacity;
	countOfVehicles = other.countOfVehicles;

	other.vehicles = nullptr;
	other.capacity = 0;
	other.countOfVehicles = 0;
}

VehicleList::VehicleList(VehicleList&& other)noexcept
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other)noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void VehicleList::resize(size_t newCap)
{
	Vehicle** resized = new Vehicle * [newCap] {nullptr};

	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i])
		{
			resized[i] = vehicles[i];
		}
	}

	delete[]vehicles;
	vehicles = resized;
	capacity = newCap;
}

VehicleList::~VehicleList()
{
	free();
}

bool VehicleList::isRepeat(const char* regNum)
{
	if (regNum == nullptr)
	{
		return false;
	}

	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i]!=nullptr && strcmp(vehicles[i]->getRegistation(), regNum) == 0)
		{
			return true;
		}
	}
	return false;
}

size_t VehicleList::size()const
{
	return countOfVehicles;
}

size_t VehicleList::getCapacity()const
{
	return capacity;
}

const Vehicle* const* VehicleList::getList()const
{
	return vehicles;
}

size_t VehicleList::getFirstFreeSlot()const
{
	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i] == nullptr)
		{
			return i;
		}
	}
	return capacity;//all slots are taken
}

size_t VehicleList::getFirstTakenSlot()const
{
	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i] != nullptr)
		{
			return i;
		}
	}
	return capacity;//there is no taken slot
}

VehicleList& VehicleList::operator+=(const Vehicle& vehicle)
{
	if (isRepeat(vehicle.getRegistation()) || !vehicle.isValid())
	{
		return *this;
	}

	if (capacity == countOfVehicles)
	{
		resize(capacity * 2);
	}

	size_t index = getFirstFreeSlot();
	vehicles[index] = new Vehicle(vehicle);
	countOfVehicles++;

	return *this;
}

VehicleList& VehicleList::operator-=(const Registration& regNum)
{
	if (!isRepeat(regNum.getPlate()))
	{
		return *this;
	}

	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i] != nullptr &&
			strcmp(vehicles[i]->getRegistation(), regNum.getPlate()) == 0)
		{
			delete vehicles[i];
			vehicles[i] = nullptr;
			countOfVehicles--;
			break;
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& v)
{
	for (size_t i = 0;i < v.capacity;i++)
	{
		if (v.vehicles[i])
		{
			os << *v.vehicles[i];
		}
		else
		{
			os << "[*]" << '\n';
		}
	}
	return os;
}

Vehicle& VehicleList::operator[](size_t index)
{
	return *vehicles[index];//exception for index if it is out of range or nullptr
}

const Vehicle& VehicleList::operator[](size_t index)const
{
	return *vehicles[index];//exception for index if it is out of range or nullptr
}

std::strong_ordering operator<=>(const VehicleList& lhs, const VehicleList& rhs)
{
	auto cmpCount = lhs.size() <=> rhs.size();

	if (cmpCount != 0)
	{
		return cmpCount;
	}

	if (lhs.isEmpty() && rhs.isEmpty())
	{
		return std::strong_ordering::equal;
	}
	else if (lhs.isEmpty())
	{
		return std::strong_ordering::less;
	}
	else if (rhs.isEmpty())
	{
		return std::strong_ordering::greater;
	}

	size_t index1 = lhs.getFirstTakenSlot();
	size_t index2 = rhs.getFirstTakenSlot();

	return lhs[index1].getRegistation() <=> rhs[index2].getRegistation();
}

size_t VehicleList::operator()(const char* code)const
{
	if (code == nullptr || strlen(code) > 2)
	{
		return 0;
	}
	size_t count = 0;

	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i])
		{
			if (strcmp(vehicles[i]->getRegistationCode(), code) == 0)
			{
				count++;
			}
		}
	}

	return count;
}

VehicleList::operator bool()const
{
	return countOfVehicles > 0;
}

bool VehicleList::isFreeSlot(size_t pos)const
{
	if (pos >= capacity)
	{
		return false;
	}

	return vehicles[pos] == nullptr;
}

bool VehicleList::isEmpty()const
{
	return countOfVehicles == 0;
}

Vehicle* VehicleList::find(const Registration& regNum)const
{
	if (regNum.getPlate() == nullptr)
	{
		return nullptr;
	}

	for (size_t i = 0;i < capacity;i++)
	{
		if (vehicles[i] != nullptr &&
		strcmp(vehicles[i]->getRegistation(), regNum.getPlate()) == 0)
		{
			return vehicles[i];
		}
	}

	return nullptr;
}

bool operator==(const VehicleList& lhs, const VehicleList& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}

	for (size_t i = 0;i < lhs.getCapacity();i++)
	{
		if (lhs.getList()[i] != nullptr)
		{
			const Registration& registration = lhs.getList()[i]->getRegistation();
			if (rhs.find(registration) == nullptr)
			{
				return false;
			}
		}
	}
	return true;
}