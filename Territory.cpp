#include "Territory.h"

Territory::Territory() : dangerLevel(1)
{
}

Territory::Territory(const Territory& other) : dangerLevel(other.dangerLevel) {
    for (const auto& landmark : other.landmarks) {
        if (landmark) {
            this->landmarks.push_back(landmark->clone());
        }
    }
}

Territory& Territory::operator=(const Territory& other)
{
    if (this != &other) {
        this->dangerLevel = other.dangerLevel;
        this->landmarks.clear(); 

        for (const auto& landmark : other.landmarks) {
            if (landmark) {
                this->landmarks.push_back(landmark->clone());
            }
        }
    }
    return *this;
}

void Territory::addLandmark(std::unique_ptr<Landmark> landmark)
{
    if (landmark) {
        landmarks.push_back(std::move(landmark));
    }
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
    for (auto it = landmarks.begin(); it != landmarks.end(); ++it) {
        if ((*it)->getType() == name) { 
            std::unique_ptr<Landmark> removed = std::move(*it);
            landmarks.erase(it);
            return removed;
        }
    }
    throw std::invalid_argument("Landmark not found: " + name);
}

void Territory::setDangerLevel(int level)
{
    if (level < 1 || level > 10) {
        throw std::invalid_argument("Danger level must be between 1 and 10.");
    }
    dangerLevel = level;
}

int Territory::getDangerLevel() const
{
    return dangerLevel;
}

bool Territory::hasLandmark(const std::string& name) const
{
    for (const auto& lm : landmarks) {
        if (lm && lm->getName() == name) {
            return true;
        }
    }
    return false;
}

void Territory::print() const
{
    std::cout << "Territory Danger Level: " << dangerLevel << "\n";
    std::cout << "Landmarks in this territory:\n";
    if (landmarks.empty()) {
        std::cout << "  (none)\n";
        return;
    }

    for (const auto& lm : landmarks) {
        if (lm) {
            std::cout << "  - ";
            lm->print(); 
        }
    }
}

