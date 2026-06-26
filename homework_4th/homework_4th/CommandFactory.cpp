#include "CommandFactory.h"
#include "SetDangerLevelCommand.h"
#include "RemoveLandmark.h"
#include "АddLandmarkCommand.h"
#include <memory>
#include <stdexcept>
#include "LandmarkFactory.h"

std::unique_ptr<Command> CommandFactory::create(const std::string& type, const std::string& args,
	Territory& territory)
{	
	if (type == "add")
	{
		std::unique_ptr<Landmark> newLandmark = LandmarkFactory::create(args);
		return std::make_unique<АddLandmarkCommand>(territory, std::move(newLandmark));
	}

	else if (type == "remove")
	{
		std::string landmarkNameRemoving = args;
		return std::make_unique<RemoveLandmark>(territory, landmarkNameRemoving);
	}
	else if (type == "danger")
	{
		unsigned int dangerLevel = std::stoi(args);
		return std::make_unique<SetDangerLevelCommand>(territory, dangerLevel);
	}
	else
	{
		throw std::invalid_argument("The type was not found!");
	}
}
