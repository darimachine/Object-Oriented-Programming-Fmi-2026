#pragma once
#include <iostream>
#include "cartographer.h"

class FieldSurveyor : public Cartographer {
    std::string region = "";

public:
    FieldSurveyor(const std::string& n, unsigned y, const std::string& r) 
        : Cartographer(n, y), region(r) {}

    std::string getRole() const override { return "Field Surveyor"; }

    void print() const override {
        std::cout << "Field Surveyor: " << name << ", Exp: " << yearsExperience << " years, Region: " << region << "\n";
    }
};