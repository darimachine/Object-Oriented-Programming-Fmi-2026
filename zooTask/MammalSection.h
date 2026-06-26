#pragma once
#include "Section.h"

class MammalSection : public Section {

public:

    MammalSection(const std::string& name);
    bool addExhibit(std::shared_ptr<Exhibit> exhibit) override;
};

