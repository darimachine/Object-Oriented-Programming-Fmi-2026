#include "Territory.h"
#include <stdexcept>
#include <iostream>

Territory::Territory(const std::string& name, int dangerLevel) : name(name), dangerLevel(dangerLevel)
{
	if (dangerLevel < 1 || dangerLevel > 10)
	{
		throw std::invalid_argument("Danger level must be between 1 and 10.");
	}
}

Territory::Territory(const Territory& other) : name(other.name), dangerLevel(other.dangerLevel)
{
	for (const auto& landmark : other.landmarks)
	{
		landmarks.push_back(landmark->clone());
	}
}

Territory& Territory::operator=(const Territory& other)
{
	if (this != &other)
	{
		name = other.name;
		dangerLevel = other.dangerLevel;
		landmarks.clear();
		for (const auto& landmark : other.landmarks)
		{
			landmarks.push_back(landmark->clone());
		}
	}
	return *this;
}

void Territory::addLandmark(std::unique_ptr<Landmark> landmark)
{
	landmarks.push_back(std::move(landmark));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
	auto landmarkToRemove = std::find_if(landmarks.begin(), landmarks.end(),
		[&name](const std::unique_ptr<Landmark>& landmark)
		{
			return landmark->getName() == name;
		});

	if (landmarkToRemove == landmarks.end())
	{
		throw std::invalid_argument("Landmark not found: " + name);
	}
	auto removed = std::move(*landmarkToRemove);
	landmarks.erase(landmarkToRemove);
	return removed;
}

void Territory::setDangerLevel(int level)
{
	if (level < 1 || level > 10)
	{
		throw std::invalid_argument("Danger level must be between 1 and 10.");
	}
	dangerLevel = level;
}

bool Territory::hasLandmark(const std::string& name) const
{
	for (const auto& landmark : landmarks)
	{
		if (landmark->getName() == name)
		{
			return true;
		}
	}
	return false;
}

void Territory::print() const {
	std::cout << "Territory: " << name << " | Danger: " << dangerLevel << " | Landmarks: " << landmarks.size() << std::endl;
	for (const auto& landmark : landmarks)
	{
		landmark->print();
	}
}

const std::string& Territory::getName() const 
{
	return name;
}

int Territory::getDangerLevel() const
{
	return dangerLevel;
}

const std::vector<std::unique_ptr<Landmark>>& Territory::getLandmarks() const
{
	return landmarks;
}
