//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "CPU.h"

#include <stdexcept>
#include <iostream>

CPU::CPU() = default;

CPU::CPU(const unsigned short cores, const unsigned short clockSpeed) : Component("CPU"),
    cores(cores), clockSpeed(clockSpeed) {

    if (cores < 1 || cores > 8) throw std::invalid_argument("Count of CPU cores must be between 1 and 8");
}

double CPU::price() const {

    return PRICE_PER_CORE * cores;
}

void CPU::output(std::ostream &output) const {

    std::print(output, "The CPU has {} cores, running at {} MHz", cores, clockSpeed);
}

std::unique_ptr<Component> CPU::clone() const {

    return std::make_unique<CPU>(*this);
}
