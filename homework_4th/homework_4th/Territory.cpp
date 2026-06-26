#include "Territory.h"
#include <algorithm>
Territory::Territory(std::vector<std::unique_ptr<Landmark>> inpLandmarks) :
	landmarks(std::move(inpLandmarks))
{
}

void Territory::addLandmark(std::unique_ptr<Landmark> joiningLandmark)
{
	landmarks.push_back(std::move(joiningLandmark));
}

std::unique_ptr<Landmark> Territory::removeLandmark(const std::string& name)
{
	auto findIt = std::find_if(landmarks.begin(),
		landmarks.end(), [&name](const std::unique_ptr<Landmark>& currL) {return currL->getName() == name; });

	if (findIt != landmarks.end())
	{
		std::unique_ptr<Landmark> extractedLandmark = std::move(*findIt);
		landmarks.erase(findIt);

		return extractedLandmark;
	}
	
	throw std::invalid_argument("The name was not found!");

}

void Territory::setDangerLever(unsigned int inpDangerLevel)
{
	if (inpDangerLevel > MAX_DANGEER)
	{
		throw std::invalid_argument("The danger can not be more than 10!");
	}

	dangerLevel = inpDangerLevel;
}

bool Territory::hasLandmark(const std::string& name) const
{
	auto findIt = std::find_if(landmarks.begin(), landmarks.end(),
		[&name](const std::unique_ptr<Landmark>& currL) {return currL->getName() == name; });

	return findIt != landmarks.end();
}

void Territory::print() const
{
	for (const auto& currL : landmarks)
	{
		currL->print();
	}
}

unsigned int Territory::getDangerLevel() const
{
	return dangerLevel;
}
