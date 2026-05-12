#pragma once
#include <string>
#include "Section.h"

class MammalSection : public Section
{
public:
	explicit MammalSection(const std::string& name);
	std::string sectionType() const override;
};

