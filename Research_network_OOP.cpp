#include <iostream>
#include "ResearchProject.h"

int main()
{
    auto ivanov = std::make_shared<Researcher>("Professor Ivanov", "AI", 45);
    auto petrova = std::make_shared<Researcher>("Associate Professor Petrova", "Robotics", 32);
    auto georgiev = std::make_shared<Researcher>("Doctor Georgiev", "ML", 18);

    ResearchProject ai("Project AI", 150000.0);
    ResearchProject robotics("Project Robotics", 80000.0);

    ai.addResearcher(ivanov);
    ai.addResearcher(petrova);
    ai.addResearcher(georgiev);
    robotics.addResearcher(ivanov);
    robotics.addResearcher(petrova);

    std::cout << ai << "\n";
    std::cout << robotics << "\n";

    ai.publishAll();
    std::cout << "After publishAll in AI:\n" << robotics << "\n";

    if (auto lead = ai.leadResearcher())
        std::cout << "Lead researcher: " << *lead << "\n";

    if (auto r = robotics.findResearcher(georgiev->getId()))
        std::cout << "Found in Robotics: " << *r << "\n";
    else
        std::cout << "Georgiev is not in Robotics\n";

    ai(ivanov->getId(), "Deep Learning")(petrova->getId(), "Computer Vision");

    std::cout << "Budget per researcher (AI): "
        << ai.totalBudgetPerResearcher() << " lv.\n";

    if (ai)       std::cout << "AI is financially stable\n";
    if (robotics) std::cout << "Robotics is financially stable\n";

    ai.removeResearcher(ivanov->getId());
    std::cout << "After removal from AI:\n" << robotics << "\n";
}