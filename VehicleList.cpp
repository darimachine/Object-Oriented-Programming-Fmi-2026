#include "VehicleList.h"

void VehicleList::resize(size_t newCap)
{

	if (newCap <= capacity) {
		return;
	}

	Vehicle** resized = new Vehicle * [newCap] {nullptr};

	for (size_t i = 0; i < capacity; i++)
	{
		resized[i] = list[i];
	}

	delete[] list;
	list = resized;
	capacity = newCap;
}

void VehicleList::copyFrom(const VehicleList& other)
{
	countOfVehicles = other.countOfVehicles;
	capacity = other.capacity;

	list = new Vehicle * [capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		if (other.list[i]) {
			list[i] = new Vehicle(*other.list[i]);
		}
		else {
			list[i] = nullptr;
		}
	}
}

void VehicleList::moveFrom(VehicleList&& other)
{
	countOfVehicles = other.countOfVehicles;
	capacity = other.capacity;
	list = other.list;

	other.countOfVehicles = 0;
	other.capacity = 0;
	other.list = nullptr;
}

void VehicleList::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete list[i];
	}
	delete[] list;
	list = nullptr;
}

VehicleList::VehicleList(size_t capacity):capacity(capacity)
{
	list=new Vehicle* [capacity] {nullptr};
}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

VehicleList::VehicleList(VehicleList&&other) noexcept
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

size_t VehicleList::getCount() const
{
	return countOfVehicles;
}

size_t VehicleList::getCapacity() const
{
	return capacity;
}

const Vehicle* const* VehicleList::getList() const
{
	return list;
}

VehicleList& VehicleList::operator+=(const Vehicle& other)
{
	if (!other.isValid()) {
		return *this;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (list[i] != nullptr &&
			strcmp(list[i]->getRegistration().getPlate(), other.getRegistration().getPlate()) == 0) {
			return *this;
		}
	}

	if (countOfVehicles >= capacity) {
		resize(capacity * 2);
	}

	for (size_t i = 0; i < capacity; i++) {
		if (list[i] == nullptr) {
			list[i] = new Vehicle(other);
			countOfVehicles++;
			return *this;
		}
	}
	return *this;
}

VehicleList& VehicleList::operator-=(const Registration& reg)
{
	if (!reg.getPlate()) {
		return *this;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (list[i]!=nullptr && strcmp(reg.getPlate(), list[i]->getRegistration().getPlate()) == 0) {
			delete list[i];
			list[i] = nullptr;
			countOfVehicles--;
			break;
		}
	}

	return *this;
}

size_t VehicleList::operator()(const char* code)const
{

	if (!code) {
		return 0;
	} 

	size_t count = 0;
	for (size_t i = 0; i < capacity; i++)
	{
		if (list[i] != nullptr) {
			const char* c = list[i]->getRegistration().getCode();
			if (strcmp(c, code) == 0) {
				count++;
			} 
		}
	}
	return count;
}

VehicleList::operator bool() const
{
	return countOfVehicles > 0;
}

const Vehicle& VehicleList::operator[](size_t index) const
{
	
	return *list[index];
}

Vehicle& VehicleList::operator[](size_t index)
{
	return *list[index];
}

bool VehicleList::isFreeSlot(size_t pos)
{
	if (pos >= capacity) {
		return false;
	}
	return list[pos] == nullptr;
}

bool VehicleList::isEmpty()
{
	return countOfVehicles == 0;
}

Vehicle* VehicleList::find(const Registration& reg) const
{
	if (!reg.getPlate()) {
		return nullptr;
	}

	for (size_t i = 0; i < capacity; i++)
	{
		if (list[i] != nullptr && strcmp(reg.getPlate(), list[i]->getRegistration().getPlate()) == 0) {
			return list[i];
		}
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list)
{
	for (size_t i = 0; i < list.capacity; i++)
	{
		if (list.list[i] == nullptr) {
			os << "* ";
		}
		else {
			os << *(list.list[i]);
		}
	}
	return os;
}

bool operator==(const VehicleList& lhs, const VehicleList& rhs)
{
	if (lhs.getCount() != rhs.getCount()) {
		return false;
	}

	for (size_t i = 0; i < lhs.getCapacity(); i++)
	{
		if (lhs.getList()[i] != nullptr)
		{
			const Registration& reg = lhs.getList()[i]->getRegistration();

			if (rhs.find(reg) == nullptr) {
				return false;
			}
		}
	}
	return true;
}

std::strong_ordering operator<=>(const VehicleList& lhs, const VehicleList& rhs)
{
	auto cmp = lhs.getCount() <=> rhs.getCount();
	if (cmp != 0) {
		return cmp;
	}

	const Vehicle* firstL = nullptr;
	const Vehicle* firstR = nullptr;

	for (size_t i = 0; i < lhs.getCapacity(); i++) {
		if (lhs.getList()[i] != nullptr) {
			firstL = lhs.getList()[i];
			break;
		}
	}

	for (size_t i = 0; i < rhs.getCapacity(); i++) {
		if (rhs.getList()[i] != nullptr) {
			firstR = rhs.getList()[i];
			break;
		}
	}

	
	if (!firstL && !firstR) {
		return std::strong_ordering::equal;
	}
	if (!firstL) {
		return std::strong_ordering::less;
	}
	if (!firstR) {
		return std::strong_ordering::greater;
	} 

	int cmpPlate = strcmp(firstL->getRegistration().getPlate(), firstR->getRegistration().getPlate());
	if (cmpPlate < 0) {
		return std::strong_ordering::less;
	}
	if (cmpPlate > 0) {
		return std::strong_ordering::greater;
	}

	return std::strong_ordering::equal;
}
