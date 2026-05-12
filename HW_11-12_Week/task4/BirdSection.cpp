#include "BirdSection.h"

BirdSection::BirdSection(const std::string& name) : Section(name, 0) 
{

}

std::string BirdSection::sectionType() const
{
	return "BirdSection";
}

