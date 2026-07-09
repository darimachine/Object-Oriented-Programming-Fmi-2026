#include "Group.h"
#include<stdexcept>

const Person& Group::operator[](const std::string& EGN)const
{
	auto it = std::find_if(people.begin(), people.end(), [&EGN](const std::unique_ptr<Person>& p)
		{
			return EGN == p->getEGN();
		});

	if (it == people.end())
	{
		throw std::logic_error("There is no person with this EGN in the group.");
	}

	return **it;
}

Person& Group::operator[](const std::string& EGN)
{
	auto it = std::find_if(people.begin(), people.end(), [&EGN](const std::unique_ptr<Person>& p)
		{
			return EGN == p->getEGN();
		});

	if (it == people.end())
	{
		throw std::logic_error("There is no person with this EGN in the group.");
	}

	return **it;
}

Group& Group::operator+=(const Person& other)
{
	for (const auto& person : people)
	{
		if (other == *person)
		{
			return *this;
		}
	}

	people.push_back(std::make_unique<Person>(other.getFirstName(), other.getSecondName(),
		other.getThirdName(), other.getEGN()));
	return *this;
}

Group Group::operator+(const Person& other)
{
	Group result = *this;
	result += other;
	return result;
}

Group& Group::operator-=(const Person& other)
{
	std::erase_if(people, [&other](const std::unique_ptr<Person>& p)
		{
			return other == *p;
		});

	return *this;
}

Group Group::operator-(const Person& other)
{
	Group result = *this;
	result -= other;
	return result;
}

size_t Group::operator()()const
{
	return people.size();
}

bool Group::operator()(const Person& person)const
{
	auto it = std::find_if(people.begin(), people.end(), [&person](const std::unique_ptr<Person>& p)
		{
			return person == *p;
		});

	if (it == people.end())
	{
		return false;
	}

	return true;
}

Group::Group(const Group& other)
{
	for (const auto& person : other.people)
	{
		people.push_back(std::make_unique<Person>(*person));
	}
}