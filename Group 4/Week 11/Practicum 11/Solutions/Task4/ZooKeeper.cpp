#include "ZooKeeper.h"

int ZooKeeper::idGenerator = 1000;

ZooKeeper::ZooKeeper(std::string name, int experience) : name(name), experience(experience), employeeID(++idGenerator) { }

int ZooKeeper::getID() const 
{ 
    return employeeID; 
}
int ZooKeeper::getExperience() const 
{
    return experience;
}
const std::string& ZooKeeper::getName() const 
{
    return name;
}