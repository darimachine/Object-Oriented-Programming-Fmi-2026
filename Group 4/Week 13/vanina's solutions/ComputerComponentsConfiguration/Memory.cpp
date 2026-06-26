#include "Memory.h"

#include <ostream>

Memory::Memory(const std::string &label, unsigned short capacity) : Component(label) {
    if (capacity > 10000) {
        throw std::invalid_argument("capacity must be less than 10000");
    }
    this->capacity = capacity;
}

double Memory::price() const {
    return capacity * MEMORY_PRICE;
}

void Memory::output(std::ostream &os) const {
    os << label << " with " << capacity << " GBs - " << price() << "€" << std::endl;
}

std::unique_ptr<Component> Memory::clone() const {
    return std::make_unique<Memory>(*this);
}
