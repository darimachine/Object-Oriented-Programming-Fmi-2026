#pragma once
#include <iostream>
#include <string>

class Cartographer {
protected:
    std::string name = "";
    unsigned yearsExperience = 0;

public:
    Cartographer(const std::string& n, unsigned y) : name(n), yearsExperience(y) {}

    virtual std::string getRole() const = 0;
    virtual void print() const = 0;
    virtual ~Cartographer() = default;
};