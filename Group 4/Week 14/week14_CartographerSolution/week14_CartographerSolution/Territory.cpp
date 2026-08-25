#include "Territory.h"

Territory::Territory(const Territory& other)
{
    const unsigned size = other.landmarks.size();

    for (unsigned i = 0; i < size; i++)
    {
    
        landmarks.push_back(other.landmarks[i]->clone());
    }
}

void Territory::addLandmark(std::unique_ptr<Landmark> landmark)
{
    if (landmark == nullptr) throw std::invalid_argument("Cannot add an empty landmark to the vector");
    landmarks.push_back(std::move(landmark));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{

    const unsigned size = landmarks.size();

    for (unsigned i = 0; i < size; i++)
    {
    
        if (landmarks[i]->getName() == name)
        {
            auto temp = landmarks[i]->clone();
            
            landmarks.erase(landmarks.begin() + i);
            
            return std::move(temp);
        }
    }
    
    throw std::invalid_argument("Landmark with such name doesn't exists");
}

void Territory::setDangetLevel(const short dangerLevel)
{

    if (dangerLevel < 0 || dangerLevel > 10)
        throw std::invalid_argument("Set danger level must be between 0 and 10");

    const unsigned size = landmarks.size();

    for (unsigned i = 0; i < size; i++)
    {
        landmarks[i]->setThreatLevel(dangerLevel);
    }
}

bool Territory::hasLandmark(const std::string& name)
{
    const unsigned size = landmarks.size();

    for (unsigned i = 0; i < size; i++)
    {

        if (landmarks[i]->getName() == name) return true;
    }

    return false;
}

void Territory::print()
{
    
    std::cout << "Territory info: " << std::endl;

    const unsigned size = landmarks.size();

    for (unsigned i = 0; i < size; i++)
    {

        landmarks[i]->print();
    }
}

unsigned Territory::getDangerLevel() const
{
    if (landmarks.empty()) return 0;
    
    return landmarks[0]->getThreatLevel();
}
