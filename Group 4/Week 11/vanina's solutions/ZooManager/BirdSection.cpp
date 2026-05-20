#include "BirdSection.h"

BirdSection::BirdSection(const std::string &name) : Section(name, MIN_BIRD_YEARS){
}

BirdSection::BirdSection(const std::string &name,
                         const ZooKeeper& keeper) : Section(name, MIN_BIRD_YEARS, keeper) {
}
