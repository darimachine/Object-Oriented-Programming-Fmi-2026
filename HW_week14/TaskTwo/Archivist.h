#pragma once
#include <string>
#include "Cartographer.h"
#include <memory>

class Archivist : public Cartographer
{
    std::string institution;
public:
    Archivist(const std::string& name, int yearsExperience, const std::string& institution);
    std::string getRole() const override;
    void print() const override;
};

