#include "Section.h"

Section::Section(std::string name, int minExperience)
	: name(name), minExperience(minExperience), guard(nullptr) {}

bool Section::assignGuard(std::shared_ptr<ZooKeeper> g)
{
    if (g && g->getExperience() >= minExperience) {
        guard = g;
        return true;
    }
    return false;
}

void Section::addExhibit(const Exhibit& e)
{
exhibits.push_back(e);
}

bool Section::hasActivteGuard() const
{
    return guard!= nullptr;
}

void Section::removeGuard()
{
guard = nullptr;
}

void Section::print() const
{
    std::cout << "  Section: " << name << " (Min Exp: " << minExperience << "y)" << std::endl;
    std::cout << "  Guard: " << (guard ? "Active" : "None") << std::endl;
    for (const auto& e : exhibits) e.print();
}

std::vector<Exhibit>& Section::getExhibit()
{
    return exhibits;
}

