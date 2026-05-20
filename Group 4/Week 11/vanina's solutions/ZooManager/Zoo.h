#ifndef ZOOMANAGER_ZOO_H
#define ZOOMANAGER_ZOO_H

#include "ZooKeeper.h"
#include "Section.h"
#include <memory>

class Zoo {
    std::vector<std::unique_ptr<Section>> sections;
    std::vector<std::shared_ptr<ZooKeeper>> keepers;

public:
    std::shared_ptr<ZooKeeper> addKeeper(const ZooKeeper &zk);
    void removeKeeper(unsigned employeeID);
    void printAll() const;
    Animal* search(const std::string& name) const;

    void addSection(std::unique_ptr<Section> section);
};


#endif //ZOOMANAGER_ZOO_H