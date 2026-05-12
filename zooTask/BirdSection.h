#pragma once
#include "Section.h"


class BirdSection : public Section {
public:

    BirdSection(const std::string& name);
    bool addExhibit(shared_ptr<Exhibit> exhibit) override;
};

