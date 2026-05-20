#include "Team.h"

bool Team::operator()(const Person& first, const Person& second)
{
	if (!Group::operator()(first) || !Group::operator()(second))
	{
		return false;
	}

	auto it = std::find_if(relations.begin(), relations.end(),
		[&first, &second](const std::pair<std::string, std::string>& r)
		{
			return r.first == second.getEGN();
		});

	if (it != relations.end())
	{
		it->second = first.getEGN();
	}
	else
	{
		relations.push_back({ second.getEGN(),first.getEGN() });
	}

	return true;
}

size_t Team::countManagers()const
{
	std::vector<std::string> managers;

	for (const auto& relation : relations)
	{
		auto it = std::find(managers.begin(), managers.end(), relation.second);
		if (it == managers.end())
		{
			managers.push_back(relation.second);
		}
	}

	return managers.size();
}

std::strong_ordering operator<=>(const Team& lhs, const Team& rhs)
{
	return lhs.countManagers() <=> rhs.countManagers();
}

bool operator==(const Team& lhs, const Team& rhs)
{
	return lhs.countManagers() == rhs.countManagers();
}