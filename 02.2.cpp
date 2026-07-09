#include "02.2.h"
#include <cstring>

void Vehicle::copyFrom(const Vehicle& other) {
    text = new char[strlen(other.text) + 1];
    strcpy(text, other.text);
    year = other.year;
    power = other.power;
}

void Vehicle::free() {
    delete[] text;
    text = nullptr;
}

Vehicle::Vehicle(const Registration& reg, const char* description, int year, double power)
    : carNum(reg), text(nullptr), year(year), power(power)
{
    if (!description) { description = "None"; }
    text = new char[strlen(description) + 1];
    strcpy(text, description);
}

Vehicle::Vehicle(const Vehicle& other) : carNum(other.carNum) {
    copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        free();
        carNum = other.carNum;
        copyFrom(other);
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : carNum(other.carNum), text(other.text), year(other.year), power(other.power)
{
    other.text = nullptr;
    other.year = 0;
    other.power = 0.0;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept {
    if (this != &other) {
        free();
        carNum = other.carNum;
        text = other.text;
        year = other.year;
        power = other.power;
        other.text = nullptr;
        other.year = 0;
        other.power = 0.0;
    }
    return *this;
}

Vehicle::~Vehicle() { free(); }

const char* Vehicle::getRegNum() const { return carNum.toString(); }

std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const {
    if (year != other.year) return year <=> other.year;
    if (power < other.power) return std::strong_ordering::less;
    if (power > other.power) return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return (*this <=> other) == std::strong_ordering::equal;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v) {
    os << "Reg. Number: " << v.carNum
        << " | Year: " << v.year
        << " | Power: " << v.power << " hp"
        << "\nDescription: " << (v.text ? v.text : "N/A");
    return os;
}