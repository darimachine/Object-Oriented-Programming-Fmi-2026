#include "MammalSection.h"

MammalSection::MammalSection(const std::string& name) : Section(name, 3)
{

}

std::string MammalSection::sectionType() const
{
	return "MammalSection";
}