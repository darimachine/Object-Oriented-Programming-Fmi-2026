#ifndef ZOOMANAGER_REPTILESECTION_H
#define ZOOMANAGER_REPTILESECTION_H
#include <string>

#include "Section.h"


class ReptileSection : public Section {
public:
    ReptileSection() = default;
    ReptileSection(const std::string &name);
    ReptileSection(const std::string& name, const ZooKeeper& keeper);
};


#endif //ZOOMANAGER_REPTILESECTION_H