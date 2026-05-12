#pragma once
#include "Section.h"

class ReptileSection : public Section {

public:

    ReptileSection(const std::string& name);
    bool addExhibit(std::shared_ptr<Exhibit> exhibit) override;
};

