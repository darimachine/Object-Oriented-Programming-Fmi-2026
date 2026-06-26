#include "Animal.h"

Animal::Animal(std::string name, std::string type, int age)
{
	setName(std::move(name));
	setType(std::move(type));
	setAge(age);
}

const std::string& Animal::getName() const
{
	return name;
}

const std::string& Animal::getType() const
{
	return type;
}

int Animal::getAge() const
{
	return age;
}

void Animal::setName(std::string name)
{
	if (!name.empty()) this->name = std::move(name);
}

void Animal::setType(std::string type)
{
	if (!type.empty()) this->type = std::move(type);
}

void Animal::setAge(int age)
{
	if (age > 0) this->age = age;
}
