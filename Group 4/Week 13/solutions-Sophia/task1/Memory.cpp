#include "Memory.h"
#include <stdexcept>
#include <iostream>

Memory::Memory(const std::string& name, const unsigned short capacity) : Component(name)
{
    if (capacity < 1 || capacity >10000) {
        throw std::invalid_argument("invalid capacity!");
    }
    this->capacity = capacity;
}

double Memory::price() const
{
    return capacity * GBS_PRICE;
}

void Memory::output(std::ostream& os) const
{
    os << "label: " << label << ", capacity:" << capacity << ", price: " << price();
}

std::unique_ptr<Component> Memory::clone() const
{
    return std::make_unique<Memory>(*this);
}