#pragma once
#include "Cartographer.h"

class FieldSurveyor : public Cartographer
{

private:

    std::string region;

public:

    FieldSurveyor() = default;
    FieldSurveyor(std::string name, const unsigned yearsExperience, std::string region);
    
    [[nodiscard]] std::string getRole() const override;
    void print() const override;
};

