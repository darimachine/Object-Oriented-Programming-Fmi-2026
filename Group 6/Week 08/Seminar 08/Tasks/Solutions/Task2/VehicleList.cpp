#include "VehicleList.h"

void VehicleList::free()
{
	for (size_t i = 0; i < this->vehicleCapacity; i++)
	{
		if (this->vehicles[i] != nullptr)
		{
			delete this->vehicles[i];
			this->vehicles[i] = nullptr;
		}
		
	}
	delete[] this->vehicles;
	this->vehicles = nullptr;
}

void VehicleList::copyFrom(const VehicleList& other)
{
	this->vehicleCapacity = other.vehicleCapacity;
	this->vehicleCount = other.vehicleCount;
	this->vehicles = new Vehicle*[this->vehicleCapacity];
	for (size_t i = 0; i < vehicleCapacity; i++)
	{
		if (other.vehicles[i])
		{
			this->vehicles[i] = new Vehicle(*other.vehicles[i]);
		}
		else this->vehicles[i] = nullptr;
	}
}

void VehicleList::moveFrom(VehicleList&& other) noexcept
{
	this->vehicleCapacity = other.vehicleCapacity;
	other.vehicleCapacity = 0;
	this->vehicles = other.vehicles;
	other.vehicles = nullptr;
	this->vehicleCount = other.vehicleCount;
	other.vehicleCount = 0;
}

void VehicleList::resize(size_t newCap) {
	Vehicle** temp = new Vehicle * [newCap];
	for (size_t i = 0; i < newCap; i++) temp[i] = nullptr;

	for (size_t i = 0; i < this->vehicleCapacity; i++) {
		temp[i] = this->vehicles[i]; 
	}

	delete[] this->vehicles; 
	this->vehicles = temp;
	this->vehicleCapacity = newCap;
}

VehicleList::VehicleList() : VehicleList(8)
{ }

VehicleList::VehicleList(size_t capacity)
{
	this->vehicleCapacity = capacity;
	this->vehicleCount = 0;
	this->vehicles = new Vehicle * [this->vehicleCapacity] { nullptr };
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

VehicleList::VehicleList(VehicleList&& other) noexcept
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

VehicleList::~VehicleList()
{
	free();
}

bool VehicleList::isFreeSlot(size_t pos) const
{
	return this->vehicles[pos] == nullptr;
}

bool VehicleList::isEmpty() const
{
	return this->vehicleCount == 0;
}

size_t VehicleList::capacity() const
{
	return this->vehicleCapacity;
}

size_t VehicleList::size() const
{
	return this->vehicleCount;
}

Vehicle* VehicleList::find(const Registration& reg) const
{
	for (size_t i = 0; i < this->vehicleCapacity; i++)
	{
		if (this->vehicles[i] != nullptr && strcmp(this->vehicles[i]->getReg(), reg.c_str()) == 0)
		{
			return this->vehicles[i];
		}
	}
	return nullptr;
}

size_t VehicleList::operator()(const char* cityCode) const
{
	size_t cnt = 0;
	size_t codeLen = strlen(cityCode);
	for (size_t i = 0; i < this->vehicleCapacity; i++)
	{
		if (this->vehicles[i] == nullptr) continue;

		const char* currentReg = this->vehicles[i]->getReg();
		size_t regLen = strlen(currentReg);

		if (regLen == 7 && codeLen == 1)
		{
			if (currentReg[0] == cityCode[0]) cnt++;
		}
		else if (regLen == 8 && codeLen == 2)
		{
			if (currentReg[0] == cityCode[0] && currentReg[1] == cityCode[1]) cnt++;
		}
	}
	return cnt;
}

VehicleList::operator bool() const
{
	return this->vehicleCount > 0;
}

Vehicle* VehicleList::operator[](size_t index)
{
	return this->vehicles[index];
}

const Vehicle* VehicleList::operator[](size_t index) const
{
	return this->vehicles[index];
}

void operator+=(VehicleList& vehicleList, const Vehicle& vehicle) {
	if (vehicleList.find(vehicle.getReg()) != nullptr) return;

	if (vehicleList.vehicleCount == vehicleList.vehicleCapacity) {
		vehicleList.resize(vehicleList.vehicleCapacity * 2);
	}

	for (size_t i = 0; i < vehicleList.vehicleCapacity; i++) {
		if (vehicleList.vehicles[i] == nullptr) {
			vehicleList.vehicles[i] = new Vehicle(vehicle);
			vehicleList.vehicleCount++;
			return;
		}
	}
}

void operator-=(VehicleList& vehicleList, const Registration& regNumber) {
	for (size_t i = 0; i < vehicleList.vehicleCapacity; i++) {
		if (vehicleList.vehicles[i] != nullptr &&
			strcmp(vehicleList.vehicles[i]->getReg(), regNumber.c_str()) == 0) {

			delete vehicleList.vehicles[i];
			vehicleList.vehicles[i] = nullptr;
			vehicleList.vehicleCount--;
			return;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const VehicleList& vl)
{
	for (size_t i = 0; i < vl.vehicleCapacity; i++) 
	{
		if (vl[i] != nullptr)
			os << *vl[i] << "\n"; 
		else
			os << "*\n";
	}
	return os;
}

bool operator<(const VehicleList& vl1, const VehicleList& vl2)
{
	if (vl1.vehicleCount < vl2.vehicleCount)
	{
		return true;
	}
	if (vl1[0] && vl2[0] && strcmp(vl1[0]->getReg(), vl2[0]->getReg()) < 0) return true;
	return false;
}

bool operator==(const VehicleList& vl1, const VehicleList& vl2)
{
	if (vl1.vehicleCount != vl2.vehicleCount)
	{
		return false;
	}
	else
	{
		if(vl1[0] && vl2[0] && strcmp(vl1[0]->getReg(), vl2[0]->getReg()) != 0) return false;
	}
	return true;
}

bool operator>(const VehicleList& vl1, const VehicleList& vl2)
{
	return vl2 < vl1;
}
