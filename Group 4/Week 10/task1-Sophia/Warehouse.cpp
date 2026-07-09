#include "Warehouse.h"

Warehouse::Warehouse(const std::string warehouseName, size_t capacity)
{
}

Package *Warehouse::addPackage(const std::string trackingNumber, const std::string receiver, double weight, Priority priority)
{
    return nullptr;
}

void Warehouse::removePackage(const std::string trackingNumber)
{
}

bool Warehouse::operator[](const std::string trackingNumber)
{
    return false;
}

void Warehouse::transferTo(const std::string &trackingNumber, Warehouse &other)
{
}

Package *Warehouse::heaviestPackage() const
{
    return nullptr;
}

int Warehouse::urgentPackages() const
{
    return 0;
}

double Warehouse::totalWeight() const
{
    return 0.0;
}

Warehouse::operator bool() const
{
    return packages.size() > (capacity*0.8);
}

bool Warehouse::operator()() const
{
    return false;
}

std::string Warehouse::getWarehouseName() const {
    return warehouseName;
}

std::ostream &operator<<(std::ostream &os, const Warehouse &warehouse)
{
    os << "warehouseName: " << warehouse.getWarehouseName();

    return os;

}
