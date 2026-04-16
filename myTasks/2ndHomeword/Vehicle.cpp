#include  <iostream>
#include "Vehicle.h"

void Vehicle::setDescription(const char *descr)
{
    if (!descr)
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
        return;
    }
    horsePowers = hp;
}

void Vehicle::setProdY(int py)
{
    if (py < MIN_PROD_Y)
    {
        return;
    }
    productionYear = py;
}

Vehicle::Vehicle(const Registration &regn, const char *desc, int hp, int py): regNum(regn)
{
    setDescription(desc);
    setHorsePower(hp);
    setProdY(py);
}

std::ostream& operator<<(std::ostream& os, const Vehicle& obj)
{
    os<<"Registration num:"<<obj.regNum<<" Description: "<<obj.description<<" Horsepowers: "<<obj.horsePowers
    <<" Production year: "<<obj.productionYear<<'\n';
    return os;
}
bool operator==(const Vehicle& lhs, const Vehicle& rhs)
{
    return lhs.productionYear == rhs.productionYear;
}
std::strong_ordering Vehicle::operator<=>(const Vehicle& other) const
{
    if (auto cmp = productionYear <=> other.productionYear; cmp !=0)
    {
        return  cmp;
    }
    return  horsePowers <=> other.horsePowers;
}

int main()
{



    return 0;
}