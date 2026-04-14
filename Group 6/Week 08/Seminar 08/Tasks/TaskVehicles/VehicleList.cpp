#define _CRT_SECURE_NO_WARNINGS
#include "VehicleList.h"

void VehicleList::free() {
	for (int i = 0; i < currentSize; i++) {
		delete vehicles[i];
	}
	delete[] vehicles;
}
void VehicleList::resize() {
	Vehicle** v2 = new Vehicle * [capacity * 2]{nullptr};
	for (int i = 0; i < currentSize; i++) {
		v2[i] = vehicles[i];
	}
	delete[] vehicles;
	capacity *= 2;
	vehicles = v2;
}
VehicleList::VehicleList(size_t size) {
	vehicles = new Vehicle * [size] {nullptr};
	capacity = size;
}
int VehicleList::contains(const Vehicle& v) {
	for (int i = 0; i < currentSize; i++)
	{
		if (*vehicles[i] == v) return i;
	}
	return -1;
}

VehicleList& VehicleList::operator+=(const Vehicle& other) {
	if (contains(other)!=-1) return *this;
	if (currentSize >= capacity) resize();
	vehicles[currentSize++] = new Vehicle(other);
	return *this;
}

void VehicleList::moveFrom(VehicleList&& other) {
	this->capacity = other.capacity;
	this->currentSize = other.currentSize;
	this->vehicles = other.vehicles;

	other.currentSize = 0;
	other.capacity = 0;
	other.vehicles = nullptr;
}
void VehicleList::copyFrom(const VehicleList& other) {
	this->capacity = other.capacity;
	this->currentSize = other.currentSize;
	this->vehicles = new Vehicle * [other.capacity];
	for (int i = 0; i < currentSize; i++) {
		vehicles[i] = new Vehicle(*other.vehicles[i]);
	}
}

VehicleList::~VehicleList() {
	free();
}
VehicleList::VehicleList(const VehicleList& other) {
	copyFrom(other);
}
VehicleList::VehicleList(VehicleList&& other) noexcept {
	moveFrom(std::move(other));
}
VehicleList& VehicleList::operator=(const VehicleList& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
VehicleList& VehicleList::operator=(VehicleList&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
VehicleList& VehicleList::operator-=(const Registration& reg) {
	int index = -1;
	for (int i = 0; i < currentSize; i++) {
		if (vehicles[i]->registration() == reg) { index = i; break; }
	}
	if (index !=-1) {
		for (int i = index; i < currentSize-1; i++)
		{
			std::swap(vehicles[i], vehicles[i + 1]);
		}
		currentSize--;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, const VehicleList& list) {
	for (int i = 0; i < list.currentSize; i++) {
		os << *list.vehicles[i]<<std::endl;
	}
	for (int i = list.currentSize; i < list.capacity; i++) {
		os << '*' << std::endl;
	}
	return os;
}
std::strong_ordering VehicleList::operator<=>(const VehicleList& other) const {
	if (currentSize > other.currentSize) return std::strong_ordering::greater;
	if (currentSize < other.currentSize) return std::strong_ordering::less;
	for (int i = 0; i < currentSize; i++) {
		if (*vehicles[i] != *other.vehicles[i]) return *vehicles[i] <=> *other.vehicles[i];
	}
	return std::strong_ordering::equal;
}
int VehicleList::operator()(const char* city)const {
	int counter = 0;
	for (int i = 0; i < currentSize; i++) {
		const char* number = vehicles[i]->registration().getNumber();
		char city2[3];
		if (strlen(number) == 8) {
			city2[0] = number[0];
			city2[1] = number[1];
			city2[2] = '\0';
		}
		else {
			city2[0] = number[0];
			city2[1] = '\0';
		}
		if (strcmp(city, city2) == 0)counter++;
	}
	return counter;
}
VehicleList::operator bool() const {
	if (currentSize > 0) return true;
	return false;
}
const Vehicle& VehicleList::operator[](int i) const {
	if (i < currentSize) {
		return *vehicles[i];
	}
	throw std::out_of_range("Wrong Index");
}
Vehicle& VehicleList::operator[](int i) {
	if (i < currentSize) {
		return *vehicles[i];
	}
	throw std::out_of_range("Wrong Index");
}
bool VehicleList::isFreeSlot(int pos) const{
	if (pos >= 0 && pos < currentSize) return false;
	if (pos >= currentSize && pos < capacity) return true;
	throw std::out_of_range("Wrong Index");
}
bool VehicleList::isEmpty() const {
	if (currentSize == 0) return true;
	return false;
}
int VehicleList::getCapacity() const {
	return capacity;
}
int VehicleList::size() const {
	return currentSize;
}
Vehicle* VehicleList::find(const Registration& reg) {
	for (int i = 0; i < currentSize; i++) {
		if (vehicles[i]->registration() == reg) return vehicles[i];
	}
	return nullptr;
}
