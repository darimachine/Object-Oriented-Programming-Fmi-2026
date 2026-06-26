#pragma once
#include <string>
#include "Cartographer.h"
#include <memory>

class FieldSurveyor : public Cartographer
{
    std::string region;
public:
    FieldSurveyor(const std::string& name, int yearsExperience, const std::string& region);
    std::string getRole() const override;
    void print() const override;
};

