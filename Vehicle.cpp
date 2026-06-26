#include "Vehicle.h"
namespace {
    void deepCopyStr(char*& dest, const char* src) {
        if (!src) {
            dest = nullptr;
            return;
        }
        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
     }
}
void Vehicle::copyFrom(const Vehicle& other)
{
    r = other.r;
    deepCopyStr(descr, other.descr);
    year = other.year;
    horsepower = other.horsepower;

}

void Vehicle::moveFrom(Vehicle&& other) noexcept
{
    r = other.r;
    descr = other.descr;
    year = other.year;
    horsepower = other.horsepower;

    other.descr = nullptr;
    other.year = 0;
    other.horsepower = 0;
}

void Vehicle::free()
{
    delete[] descr;
    descr = nullptr;
}


Vehicle::Vehicle(const Registration& r, const char* descr, unsigned year, unsigned horsepower) : r(r), year(year), horsepower(horsepower)
{
    deepCopyStr(this->descr, descr);
}

Vehicle::Vehicle(const Vehicle& v) : r(v.r)
{
    copyFrom(v);
}

Vehicle& Vehicle::operator=(const Vehicle& v)
{
    if (this != &v) {
        free();
        copyFrom(v);
   }
    return *this;
}

Vehicle::Vehicle(Vehicle&& v) noexcept : r(v.r)
{
    moveFrom(std::move(v));
}

Vehicle& Vehicle::operator=(Vehicle&& v) noexcept
{
    if (this != &v) {
        free();
        moveFrom(std::move(v));
    }
    return *this;
}

Vehicle::~Vehicle()
{
    free();
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v)
{
    os << v.r << v.descr << " " << v.year << " " << v.horsepower<<" ";
    return os;
}
const Registration& Vehicle::getReg() const
{
    return r;
}
unsigned Vehicle::getYear() const {
    return year;
}
unsigned Vehicle::getHorsepower() const {
    return horsepower;
}

bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
    if (lhs.getYear() == rhs.getYear() && lhs.getHorsepower() == rhs.getHorsepower()) return true;
    return false;
}

bool operator!=(const Vehicle& lhs, const Vehicle& rhs)
{
    return !(lhs == rhs);
}

std::strong_ordering operator<=>(const Vehicle& lhs, const Vehicle& rhs)
{
    if (lhs.getYear() == rhs.getYear()) {
        return lhs.getHorsepower() <=> rhs.getHorsepower();
    }
    return lhs.getYear() <=> rhs.getYear();
}
