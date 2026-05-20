#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Exhibit.h"
#include "ZooKeeper.h"
class Section
{
    std::string name;
    int minExperience;
    std::vector<Exhibit> exhibits;
    std::weak_ptr<ZooKeeper> guard;
public:
    Section(const std::string& name, int minExperience);
    virtual ~Section() = default;
    void addExhibit(const Exhibit& exhibit);
    bool assignGuard(const std::shared_ptr<ZooKeeper>& keeper);
    bool hasActiveGuard() const;
    const std::string& getName() const;
    int getMinExp() const;
    const std::vector<Exhibit>& getExhibits() const;
    virtual std::string sectionType() const = 0;
    void print() const;
};
