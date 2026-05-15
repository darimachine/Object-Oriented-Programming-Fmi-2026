#include "ResearchProject.h"

ResearchProject::ResearchProject(const std::string& name,double budget):
	name(name),budget(budget){ }

bool ResearchProject::idExists(unsigned id)const
{
	return std::any_of(researchers.begin(), researchers.end(),
        [&id](const std::shared_ptr<Researcher>& r) {
            return r->getId() == id;
        });
}

bool ResearchProject::addResearcher(const std::shared_ptr<Researcher>& r)
{
	if (idExists(r->getId()))
	{
		return false;
	}

	researchers.push_back(r);
	return true;
}

bool ResearchProject::removeResearcher(unsigned id)
{
	if (!idExists(id))
	{
		return false;
	}

	std::erase_if(researchers, [&id](const std::shared_ptr<Researcher>& r)
		{
			return r->getId() == id;
		});

	return true;
}

Researcher* ResearchProject::operator[](unsigned id)
{
	auto it = find_if(researchers.begin(), researchers.end(),
		[&id](const std::shared_ptr<Researcher>& r)
		{
			return r->getId() == id;
		});

	if (it == researchers.end())
	{
		return nullptr;
	}

	return it->get();
}

const Researcher* ResearchProject::operator[](unsigned id)const
{
	auto it = find_if(researchers.begin(), researchers.end(),
		[&id](const std::shared_ptr<Researcher>& r)
		{
			return r->getId() == id;
		});

	if (it == researchers.end())
	{
		return nullptr;
	}

	return it->get();
}

Researcher* ResearchProject::findResearcher(unsigned id)
{
	auto researcher = (*this)[id];
	return researcher;
}

Researcher* ResearchProject::leadResearcher()const
{
	if (researchers.empty())
	{
		return nullptr;
	}

	auto it = std::max_element(researchers.begin(), researchers.end(),
		[](const std::shared_ptr<Researcher>& a, const std::shared_ptr<Researcher>& b)
		{
			return a->getPublications() < b->getPublications();
		});

	return it->get();
}

void ResearchProject::publishAll()
{
	for (const auto& i : researchers)
	{
		i->addPublications();
	}
}

double ResearchProject::totalBudgetPerResearcher()const
{
	if (researchers.empty())
	{
		return 0.0;
	}

	return budget / researchers.size();
}

std::ostream& operator<<(std::ostream& os, const ResearchProject& rp)
{
	os << "Project name: " << rp.name << " Budget: " << rp.budget << '\n';
	
	auto sorted = rp.researchers; 
	std::sort(sorted.begin(), sorted.end(),
		[](const std::shared_ptr<Researcher>& a, const std::shared_ptr<Researcher>& b)
		{
			return a->getPublications() > b->getPublications();
		});

	os << "Researchers:" << '\n';
	for (const auto& i : sorted)
	{
		os << *i;
	}

	return os;
}

ResearchProject::operator bool()const
{
	return budget > STABLE_BUDGET;
}

ResearchProject& ResearchProject::operator()(unsigned id, const std::string& sprecialization)
{
	auto researcher = (*this)[id];

	if (researcher == nullptr)
	{
		return *this;
	}

	researcher->setSpecialization(sprecialization);
	return *this;
}