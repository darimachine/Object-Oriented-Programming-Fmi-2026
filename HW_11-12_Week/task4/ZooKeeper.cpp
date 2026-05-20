#include "ZooKeeper.h"
#include "ZooException.h"
#include <iostream>
ZooKeeper::ZooKeeper(const std::string& name, unsigned employeeID, int yearsExperience) : name(name), employeeID(employeeID), yearsExperience(yearsExperience)
{
    if (name.empty())
    {
        throw ZooException("ZooKeeper name cannot be empty.");
    }
    if (employeeID == 0)
    {
        throw ZooException("Employee ID must be greater than 0.");
    }
    if (yearsExperience < 0)
    {
        throw ZooException("Years of experience cannot be negative.");
    }
}

const std::string& ZooKeeper::getName() const 
{
    return name; 
}

unsigned ZooKeeper::getID() const
{
    return employeeID;
}

int ZooKeeper::getYearsExperience() const
{
    return yearsExperience;
}

void ZooKeeper::print() const 
{
    std::cout << "ZooKeeper: " << name << " (ID " << employeeID << ", exp: " << yearsExperience << " years)" << std::endl;
}