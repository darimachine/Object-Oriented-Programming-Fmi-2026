#pragma once
#include"Section.h"

class ReptileSection:public Section
{
private:
	static constexpr unsigned MIN_EXPERIENCE = 5;

public:
	ReptileSection(const string& name);
};

