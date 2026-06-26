#pragma once
#include <string>
class ZooKeeper
{
    std::string name;
    unsigned employeeID;
    int yearsExperience;
public:
    ZooKeeper(const std::string& name, unsigned employeeID, int yearsExperience);
    const std::string& getName() const;
    unsigned getID() const;
    int getYearsExperience() const;
    void print() const;
};

