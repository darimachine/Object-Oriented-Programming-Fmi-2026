#pragma once
#include <string>
#include <iostream>

class Cartographer
{
protected:
    std::string name;
    unsigned yearsExperience = 0;

public:

    Cartographer() = default;
    Cartographer(std::string name, const unsigned yearsExperience);

    [[nodiscard]] virtual std::string getRole() const = 0;
    virtual void print() const = 0;

    virtual ~Cartographer() = default;
};

