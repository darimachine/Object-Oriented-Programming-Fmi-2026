#pragma once
#include <string>

class ZooKeeper {
    static int idGenerator;
    int employeeID;
    std::string name;
    int experience;

public:
    ZooKeeper(std::string name, int experience);

    int getID() const;
    int getExperience() const;
    const std::string& getName() const;
};