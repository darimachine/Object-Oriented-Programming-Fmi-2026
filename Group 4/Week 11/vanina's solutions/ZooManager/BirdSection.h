#ifndef ZOOMANAGER_BIRDSECTION_H
#define ZOOMANAGER_BIRDSECTION_H

#include "Section.h"


class BirdSection : public Section {
public:
    BirdSection() = default;
    BirdSection(const std::string& name);
    BirdSection(const std::string& name, const ZooKeeper& keeper);
};


#endif //ZOOMANAGER_BIRDSECTION_H