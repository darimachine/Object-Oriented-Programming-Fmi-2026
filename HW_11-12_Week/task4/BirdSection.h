#pragma once
#include <string>
#include "Section.h"

class BirdSection : public Section
{
public:
    explicit BirdSection(const std::string& name);
    std::string sectionType() const override;
};

