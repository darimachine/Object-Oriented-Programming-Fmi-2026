#pragma once
#include <string>

class ZooKeeper {
std::string name;
int employeeID;
int experienceYears;

public:
ZooKeeper(std::string n, int id, int exp);
int getID() const;
int getExperience() const;
};
