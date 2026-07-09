#pragma once
#include"Section.h"

class BirdSection:public Section
{
public:
	BirdSection() = default;
	BirdSection(const string& name, unsigned minExperience);
};

