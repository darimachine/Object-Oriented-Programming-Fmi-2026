#pragma once
#include <string>
#include <memory>

class Cartographer
{
protected:
    std::string name;
    int yearsExperience;
public:
    Cartographer(const std::string& name, int yearsExperience);
    virtual ~Cartographer() = default;
    virtual std::string getRole() const = 0;
    virtual void print() const = 0;
    const std::string& getName() const;
    int getYearsExperience() const;
};

