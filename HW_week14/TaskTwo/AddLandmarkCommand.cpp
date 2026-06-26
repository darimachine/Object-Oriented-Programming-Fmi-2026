#include "AddLandmarkCommand.h"

AddLandmarkCommand::AddLandmarkCommand(Territory& target, std::unique_ptr<Landmark> landmark) : target(target), landmark(std::move(landmark))
{
	landmarkName = this->landmark->getName();
}

void AddLandmarkCommand::execute()
{
	auto clone = landmark->clone();
	target.addLandmark(std::move(clone));
}

void AddLandmarkCommand::undo()
{
	target.removeLandmark(landmarkName);
}

std::string AddLandmarkCommand::description() const
{
	return "AddLandmark: " + landmarkName + " -> " + target.getName();
}

