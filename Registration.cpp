#define _CRT_SECURE_NO_WARNINGS
#include "Registration.h"
#include<iostream>

bool Registration::isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool Registration::isRegValid(const char* regNum)
{
    if (!regNum) return false;
    int len = strlen(regNum);

    // length 7 or 8
    if (len != 7 && len != 8)
        return false;

    int index = 0;
    // first 1 or 2 letters
    if(isLetter(regNum[0]) && isLetter(regNum[1]))
    {
        index = 2;
    }
    else if ((regNum[0] >= 'A' && regNum[0] <= 'Z') || (regNum[0] >= 'a' && regNum[0] <= 'z'))
    {
        index = 1;
    }
    else
        return false;

    // next 4 digits
    for (int i = 0; i < 4; i++) {
        if (!(regNum[index + i] > '0' && regNum[index + i] < '9'))
            return false;
    }

    index += 4;
    // last 2 letters
    if (!isLetter(regNum[index]) || !isLetter(regNum[index + 1]))
        return false;

    return true;
}

Registration::Registration(const char* regNum)
{
    if (!isRegValid(regNum)) {
        throw std::invalid_argument("Invalid registration number!");
    }
    strcpy(reg, regNum);
}

auto Registration::operator<=>(const Registration& other) const
{
    return strcmp(reg, other.reg) <=> 0;
}

bool Registration::operator==(const Registration& other) const
{
    return strcmp(reg, other.reg) == 0;
}

const char* Registration::getReg() const
{
    return reg;
}

std::ostream& operator<<(std::ostream& os, const Registration& r)
{
    os << r.reg;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& v)
{
    os << v.reg << " | " << v.description << " | year " << v.year << " | " << v.power << " horsepower";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VehicleList& list)
{
    for (int i = 0; i < list.cap; i++)
    {
        if (list.listVehicle[i])
            os << *list.listVehicle[i] << "\n";
        else
            os << "***\n";
    }
    return os;
}

Vehicle::Vehicle(const Registration& regN, const char* _description, int _year, int _power)
    : year(_year), power(_power), reg(regN)
{
    description = new char[strlen(_description) + 1];
    strcpy(description, _description);

}

Vehicle::Vehicle(const Vehicle& other)
    : reg(other.reg),
    year(other.year),
    power(other.power)
{
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept
    : reg(std::move(other.reg)),
    year(other.year),
    power(other.power),
    description(other.description)
{
    other.description = nullptr;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
    if (this != &other)
    {
        free();

        reg = other.reg;
        year = other.year;
        power = other.power;

        description = other.description;
        other.description = nullptr;
    }
    return *this;
}

Vehicle::~Vehicle()
{
    free();
}

auto Vehicle::operator<=>(const Vehicle& other) const
{
    auto cmp = year <=> other.year;
    if (cmp != 0) return cmp;
    return power <=> other.power;
}

bool Vehicle::operator==(const Vehicle& other) const
{
    return (year == other.year && power == other.power && reg == other.reg);
}

void Vehicle::copyFrom(const Vehicle& other)
{
    reg = other.reg;
    year = other.year;
    power = other.power;
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

void Vehicle::free()
{
    delete[] description;
}

const Registration& Vehicle::getRegNum() const
{
    return reg;
}

bool VehicleList::isFreeSlot(int pos) const
{
    return pos < cap && listVehicle[pos] == nullptr;
}

bool VehicleList::isEmpty() const
{
    return vCount == 0;
}

Vehicle* VehicleList::find(const Registration& reg) const
{
    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i] && listVehicle[i]->getRegNum() == reg)
            return listVehicle[i];
    }

    return nullptr;
}

int VehicleList::size() const
{
    return vCount;
}

int VehicleList::capacity() const
{
    return cap;
}

void VehicleList::free()
{
    for (int i = 0; i < cap; i++)
    {
        delete listVehicle[i];
    }
    delete[] listVehicle;

    listVehicle = nullptr;
    cap = 0;
    vCount = 0;
}

void VehicleList::copyFrom(const VehicleList& other)
{
    cap = other.cap;
    vCount = other.vCount;

    listVehicle = new Vehicle* [cap];
    for (int i = 0; i < cap; i++)
    {
        if (other.listVehicle[i])
            listVehicle[i] = new Vehicle(*other.listVehicle[i]);
        else
            listVehicle[i] = nullptr;
    }
}

void VehicleList::moveFrom(VehicleList&& other)
{
    listVehicle = other.listVehicle;
    cap = other.cap;
    vCount = other.vCount;

    other.listVehicle = nullptr;
    other.cap = 0;
    other.vCount = 0;
}

void VehicleList::resize()
{
    int newCap = cap * 2;
    Vehicle** temp = new Vehicle * [newCap];

    for (int i = 0; i < newCap; i++)
    {
        temp[i] = nullptr;
    }

    for (int i = 0; i < cap; i++)
    {
        temp[i] = listVehicle[i];
    }

    delete[] listVehicle;
    listVehicle = temp;
    cap = newCap;
}

VehicleList::VehicleList(int _cap):cap(_cap)
{
    vCount = 0;
    listVehicle = new Vehicle * [cap];
    for (int i = 0; i < cap; i++)
        listVehicle[i] = nullptr;
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

auto VehicleList::operator<=>(const VehicleList& other) const
{
    if (vCount != other.vCount)
        return vCount <=> other.vCount;

    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i] && other.listVehicle[i])
        {
            auto cmp = listVehicle[i]->getRegNum() <=> other.listVehicle[i]->getRegNum();
            if (cmp != 0) return cmp;
        }
    }

    return std::strong_ordering::equal;
}

bool VehicleList::operator==(const VehicleList& other) const
{
    if (vCount != other.vCount) return false;

    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i] == nullptr && other.listVehicle[i] != nullptr)
            return false;

        if (listVehicle[i] != nullptr && other.listVehicle[i] == nullptr)
            return false;

        if (listVehicle[i] && other.listVehicle[i])
        {
            if (!(*listVehicle[i] == *other.listVehicle[i]))
                return false;
        }
    }
    return true;
}

Vehicle* VehicleList::operator[](int index)
{
    if (index < 0 || index >= cap)
        return nullptr;

    return listVehicle[index];
}

const Vehicle* VehicleList::operator[](int index) const
{
    if (index < 0 || index >= cap)
        return nullptr;

    return listVehicle[index];
}

VehicleList::~VehicleList()
{
    free();
}

VehicleList& VehicleList::operator+=(const Vehicle& v)
{
    if (find(v.getRegNum()) != nullptr)
        return *this;

    if (vCount == cap)
        resize();

    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i] == nullptr)
        {
            listVehicle[i] = new Vehicle(v);
            vCount++;
            break;
        }
    }

    return *this;
}

VehicleList& VehicleList::operator-=(const Registration& reg)
{
    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i] && listVehicle[i]->getRegNum() == reg)
        {
            delete listVehicle[i];
            listVehicle[i] = nullptr;
            vCount--;
            return *this;
        }
    }

    return *this;
}

int VehicleList::operator()(const char* townCode) const
{
    int count = 0;

    for (int i = 0; i < cap; i++)
    {
        if (listVehicle[i])
        {
            if (strncmp(listVehicle[i]->getRegNum().getReg(), townCode, strlen(townCode)) == 0)
                count++;
        }
    }
    return count;
}

VehicleList::operator bool() const
{
    return vCount > 0;
}