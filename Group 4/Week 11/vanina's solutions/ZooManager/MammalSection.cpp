#include "MammalSection.h"

MammalSection::MammalSection(const std::string &name) : Section(name, MIN_MAMMAL_YEARS) {
}

MammalSection::MammalSection(const std::string &name,
                             const ZooKeeper &keeper) : Section(name, MIN_MAMMAL_YEARS, keeper) {
}
