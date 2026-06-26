//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "ROM.h"
#include <stdexcept>

ROM::ROM(const unsigned short capacity) : Memory("ROM", capacity){
}

double ROM::price() const {
    return PRICE_PER_GB * capacity;
}

std::unique_ptr<Component> ROM::clone() const {
    return std::make_unique<ROM>(*this);
}
