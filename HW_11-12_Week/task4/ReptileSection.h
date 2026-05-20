#pragma once
#include <string>
#include "Section.h"

class ReptileSection : public Section 
{
public:
    explicit ReptileSection(const std::string& name);
    std::string sectionType() const override;
};
