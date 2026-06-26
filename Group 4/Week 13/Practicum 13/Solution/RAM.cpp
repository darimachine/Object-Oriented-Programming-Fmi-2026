//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "RAM.h"
#include <stdexcept>

RAM::RAM(const unsigned short capacity) : Memory("RAM", capacity){

    if (capacity < 1 || capacity > 128) throw std::invalid_argument("RAM's capacity must be between 1 and  128 GB");
}

double RAM::price() const {
    return PRICE_PER_GB * capacity;
}

std::unique_ptr<Component> RAM::clone() const {

    return std::make_unique<RAM>(*this);
}
