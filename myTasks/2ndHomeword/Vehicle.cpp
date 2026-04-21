#include  <iostream>
#include "Vehicle.h"

void Vehicle::setDescription(const char *descr)
{
    delete [] description;
    if (descr != nullptr)
    {
        size_t descrLen = strlen(descr);
        description = new char[descrLen + 1];
        strcpy(description, descr);
    }
    else
    {
        description = nullptr;
    }
}

void Vehicle::setHorsePower(int hp)
{
    if (hp < MIN_HORSE_P)
    {
        hp = MIN_HORSE_P;
        return;
    }
    horsePowers = hp;
}

void Vehicle::setProdY(int py)
{
    if (py < MIN_PROD_Y)
    {
        productionYear = MIN_PROD_Y;
        return;
    }
    productionYear = py;
}

Vehicle::Vehicle(const Registration &regn, const char *desc, int hp, int py)
{
    setDescription(desc);
    setHorsePower(hp);
    setProdY(py);
}

std::ostream& operator<<(std::ostream& os, const Vehicle& obj)
{
    os<<"Registration num:"<<obj.regNum<<" Description: "<<(obj.description ? obj.description: "No description")<<
    " Horsepowers: "<<obj.horsePowers
    <<" Production year: "<<obj.productionYear<<'\n';
    return os;
}
bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
    return (lhs.productionYear == rhs.productionYear) && (lhs.horsePowers == rhs.horsePowers);
}
std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const
{
    if (auto cmp = productionYear <=> other.productionYear; cmp !=0)
    {
        return  cmp;
    }
    return  horsePowers <=> other.horsePowers;
}


void Vehicle::copyFrom(const Vehicle &other)
{

    productionYear = other.productionYear;
    horsePowers = other.horsePowers;

    if (other.description != nullptr)
    {
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    else
    {
        description = nullptr;
    }
    regNum = other.regNum;
}

void Vehicle::moveFrom(Vehicle &&other)
{
    productionYear = other.productionYear;
    horsePowers = other.horsePowers;
    description = other.description;
    regNum = other.regNum;

    other.productionYear =0;
    other.horsePowers = 0;
    other.description = nullptr;
}

Vehicle::Vehicle(const Vehicle &other): regNum(other.regNum)
{
    copyFrom(other);
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::Vehicle(Vehicle &&other)
{
    moveFrom(std::move(other));
}

Vehicle &Vehicle::operator=(Vehicle &&other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Vehicle::free()
{
    delete [] description;
    description = nullptr;
}

Vehicle::~Vehicle()
{
    free();
}

const Registration &Vehicle::getRegistration() const
{
    return regNum;
}

// int main()
// {
//
//
//
//     return 0;
// }