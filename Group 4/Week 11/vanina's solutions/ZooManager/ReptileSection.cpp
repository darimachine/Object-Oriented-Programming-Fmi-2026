#include "ReptileSection.h"

ReptileSection::ReptileSection(const std::string &name) : Section(name, MIN_REPTILE_YEARS) {
}

ReptileSection::ReptileSection(const std::string &name,
                               const ZooKeeper &keeper) : Section(name, MIN_REPTILE_YEARS, keeper) {
}
