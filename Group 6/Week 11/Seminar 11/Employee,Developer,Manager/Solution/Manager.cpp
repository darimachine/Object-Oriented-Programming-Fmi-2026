#include "Manager.h"

Manager::Manager(const string& name, const string& email, double salary, const string& department) : Employee(name,email,salary),department(department)
{

}

void Manager::addSubordinate(const string& name)
{
	subordinates.push_back(name);
}


int Manager::getTeamSize() const
{
	return subordinates.size();
}

void Manager::print() const {
    Employee::print();   // извежда name, email, salary
    std::cout << "Отдел: " << department << "\n"
        << "Подчинени: ";
    for (const auto& s : subordinates)
        std::cout << s << " ";
    std::cout << "\n";
}
