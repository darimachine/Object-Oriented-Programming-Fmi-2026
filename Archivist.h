#pragma once
#include <iostream>
#include "cartographer.h"

class Archivist : public Cartographer {
    std::string institution = "";

public:
    Archivist(const std::string& n, unsigned y, const std::string& inst);

    std::string getRole() const override;

    void print() const override;
};