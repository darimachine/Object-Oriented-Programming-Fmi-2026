#include "Territory.h"
#include <iostream>
#include <vector>
#include <algorithm>

void Territory::addLandmark(std::unique_ptr<Landmark> l)
{
	landmarks.push_back(std::move(l));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
    auto it = std::find_if(landmarks.begin(), landmarks.end(), [name](const std::unique_ptr<Landmark>& l)
        { return l->getName() == name; });

    if (it != landmarks.end()) {
        std::unique_ptr<Landmark> removedElement = std::move(*it);
        landmarks.erase(it);
        return removedElement;
    }

    else throw std::invalid_argument("Invalid name!");
}

void Territory::setDangerLevel(int level)
{
    if (level < 1 || level>10)
        throw std::invalid_argument("");
    else dangerLevel = level;
}

int Territory::getDangerLevel() const
{
    return dangerLevel;
}

bool Territory::hasLandmark(const std::string& name) const
{
    auto it = std::find_if(landmarks.begin(), landmarks.end(), [name](const std::unique_ptr<Landmark>& l)
        { return l->getName() == name; });
    if (it != landmarks.end()) return true;
    return false;
}

void Territory::print() const
{
    std::cout << "Danger level: " << dangerLevel << '\n';
    std::cout << "\nLandmarks:\n";

    for (const auto& landmark : landmarks)
    {
        landmark->print();
        std::cout << std::endl;
    }
}

Territory::Territory(int level)
{
    if (level < 1 || level > 10)
    {
        throw std::invalid_argument("Danger level must be between 1 and 10");
    }
    this->dangerLevel = level;
}

Territory::Territory(const Territory& other) {
    this->dangerLevel = other.dangerLevel;
    for (const auto& landmark : other.landmarks)
    {
        this->landmarks.push_back(landmark->clone());
    }
}