#pragma once
#include "Section.h"
#include <memory>
#include <vector>

class Zoo {
    std::vector<std::unique_ptr<Section>> sections;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;

public:
    void addSection(std::unique_ptr<Section> s);
    std::shared_ptr<ZooKeeper> addKeeper(std::string name, int exp);
    void removeKeeper(int id);
    void printAll() const;
    void search(const std::string& name) const;

    Section* getSection(size_t index);
};