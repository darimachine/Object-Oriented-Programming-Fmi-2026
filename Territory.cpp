#include "Territory.h"
#include<stdexcept>
#include<print>

void Territory::addLandmark(unique_ptr<Landmark> landmark)
{
	landmarks.push_back(move(landmark));
}

unique_ptr<Landmark> Territory::removeLandmark(const string& name)
{
	auto it = find_if(landmarks.begin(), landmarks.end(), [&name](const unique_ptr<Landmark>& l)
		{
			return l->getName() == name;
		});

	if (it == landmarks.end())
	{
		throw invalid_argument("Landmark not found.");
	}

	auto removedLandmark = move(*it);
	landmarks.erase(it);
	return removedLandmark;
}

void Territory::setDangerLevel(int dangerLevel)
{
	if (dangerLevel < MIN_DANGER_LEVEL || dangerLevel > MAX_DANGER_LEVEL)
	{
		throw invalid_argument("Danger level must be between 1 - 10");
	}
	this->dangerLevel = dangerLevel;
}

bool Territory::hasLandmark(const string& name)
{
	auto it = find_if(landmarks.begin(), landmarks.end(), [&name](const unique_ptr<Landmark>& l)
		{
			return l->getName() == name;
		});

	if (it == landmarks.end())
	{
		return false;
	}
	return true;
}


void Territory::print()const
{
	println("Territory (danger level: {}):", dangerLevel);
	for (const auto& landmark : landmarks)
	{
		landmark->print();
	}
}

int Territory::getDangerlevel() const
{
	return dangerLevel;
}
