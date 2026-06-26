#include "ReptileSection.h"

ReptileSection::ReptileSection(const std::string& name) : Section(name, 5)
{

}

std::string ReptileSection::sectionType() const
{
	return "ReptileSection";
}
