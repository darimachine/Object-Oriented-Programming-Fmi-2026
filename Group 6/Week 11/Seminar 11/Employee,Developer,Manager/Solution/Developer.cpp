#include "Developer.h"
Developer::Developer(const string& name, const string& email, double salary, const string& language) : Employee(name, email, salary), language(language)
{

}

void Developer::addTechnology(const string& tech)
{
	technologies.push_back(tech);
}

bool Developer::hasTechnology(const string& tech) const
{
	for (const auto& el : technologies) {
		if (el == tech) {
			return true;
		}
	}
	return false;
}
void Developer::print() const {
	Employee::print();   // извежда name, email, salary
	std::cout << "Език: " << language << "\n"
		<< "Технологии: ";
	for (const auto& t : technologies)
		std::cout << t << " ";
	std::cout << "\n";
}

ostream& operator<<(ostream& os, const Developer& d)
{
	os << static_cast<const Employee&>(d);
	os << " Opaaaa  ";
	return os;
}
