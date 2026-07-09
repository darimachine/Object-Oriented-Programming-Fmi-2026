#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"

void Vehicle::free() {
	delete[] description;
}

Vehicle::Vehicle(const Registration& r,const char* description, int year, int hp) : number(r) {
	if (!description) {
		throw std::invalid_argument("Description is null");
	}
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
	this->year = year;
	this->hp = hp;
}
Vehicle::Vehicle(const Vehicle& other) : number(other.number), year(other.year), hp(other.hp) {
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}
Vehicle& Vehicle::operator=(const Vehicle& other) {
	if (this != &other) {
		delete[] description;
		number = other.number;
		year = other.year;
		hp = other.hp;
		description = new char[strlen(other.description) + 1];
		strcpy(description, other.description);
	}
	return *this;
}
Vehicle::Vehicle(Vehicle&& other) noexcept : number(other.number), year(year), hp(other.hp){
	description = other.description;
	other.description = nullptr;
}
Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
	if (this != &other) {
		delete[] description;
		number = other.number;
		year = other.year;
		hp = other.hp;
		description = other.description;
		other.description = nullptr;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
	os << v.number << " " << v.description << " " << v.year << " " << v.hp;
	return os;
}
std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const{
	if (year > other.year) return std::strong_ordering::greater;
	if (year < other.year) return std::strong_ordering::less;
	
	if (hp > other.hp) return std::strong_ordering::greater;
	if (hp < other.hp) return std::strong_ordering::less;

	return std::strong_ordering::equal;
}
bool Vehicle::operator==(const Vehicle& other) const {
	return year == other.year && hp == other.hp;
}
Vehicle::~Vehicle() {
	free();
}
const Registration& Vehicle::registration()const {
	return number;
}
