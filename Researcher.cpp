#include "Researcher.h"

unsigned Researcher::nextId = 0;

Researcher::Researcher(const std::string& name, const std::string& specialization, unsigned publications):
	name(name),id(++nextId),specialization(specialization),publications(publications){ }

std::ostream& operator<<(std::ostream& os, const Researcher& r)
{
	return os << r.id << " " << r.name << " " << r.specialization << " " << r.publications << '\n';
}

unsigned Researcher::getId()const
{
	return id;
}

unsigned Researcher::getPublications()const
{
	return publications;
}

void Researcher::addPublications()
{
	++publications;
}

void Researcher::setSpecialization(const std::string& specialization)
{
	this->specialization = specialization;
}