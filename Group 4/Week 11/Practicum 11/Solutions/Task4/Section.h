#pragma once
#include "Exhibit.h"
#include "ZooKeeper.h"
#include <memory>
#include <vector>

class Section {
protected:
    std::string name;
    int minExperience;
    std::vector<Exhibit> exhibits;
    std::weak_ptr<ZooKeeper> activeGuard;

public:
    Section(std::string name, int minExp);
    virtual ~Section() = default;

    void addExhibit(const Exhibit& e);
    bool assignGuard(std::shared_ptr<ZooKeeper> guard);
    bool hasActiveGuard() const;

    const std::string& getName() const;
    const std::vector<Exhibit>& getExhibits() const;
};

class BirdSection : public Section { public: BirdSection(); };
class MammalSection : public Section { public: MammalSection(); };
class ReptileSection : public Section { public: ReptileSection(); };