#pragma once
#include "Section.h"
#include "ZooKeeper.h"


class Zoo {
    std::vector<std::unique_ptr<Section>> sections;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;

    public:
    void addSection(std::unique_ptr<Section> s);
    std::shared_ptr<ZooKeeper> addKeeper(std::string name, int id, int exp);

    void removeKeeper(int id);

    void printAll() const;

    void search(std::string name) const;

    Section* getSection(int index);
};
