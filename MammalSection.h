#pragma once
#include"Section.h"

class MammalSection:public Section
{
private:
	static constexpr unsigned MIN_EXPERIENCE = 3;
public:
	MammalSection(const string& name);
};

