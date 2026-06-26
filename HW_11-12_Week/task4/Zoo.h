#pragma once
#include <vector>
#include <memory>
#include "Section.h"
class Zoo
{
    std::vector<std::unique_ptr<Section>>   sections;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;
public:
    void addSection(std::unique_ptr<Section> section);
    std::shared_ptr<ZooKeeper> addKeeper(const std::string& name, unsigned id, int exp);
    void removeKeeper(unsigned employeeID);
    void printAll() const;
    const Animal* search(const std::string& name) const;
};

