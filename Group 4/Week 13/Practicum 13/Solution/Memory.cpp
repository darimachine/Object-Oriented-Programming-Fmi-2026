//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "Memory.h"

#include <iostream>
#include <stdexcept>

Memory::Memory() = default;

Memory::Memory(std::string label, const unsigned short capacity) : Component(std::move(label)),
    capacity(capacity){

    if (capacity < 1 || capacity > 10000) throw std::invalid_argument("Memory's capacity must be between 1 and 10000 GB");
}

void Memory::output(std::ostream &output) const {

    std::print(output, "The {} memory has {} GB", label, capacity);
}
