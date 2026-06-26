#ifndef ZOOMANAGER_MAMMALSECTION_H
#define ZOOMANAGER_MAMMALSECTION_H

#include "Section.h"


class MammalSection : public Section {
public:
    MammalSection() = default;
    explicit MammalSection(const std::string& name);
    MammalSection(const std::string& name, const ZooKeeper& keeper);
};


#endif //ZOOMANAGER_MAMMALSECTION_H