#include "Command.h"
#include <iostream>
#include <string>

AddLandmarkCommand::AddLandmarkCommand(Territory& t, std::unique_ptr<Landmark> l) : territory(t), landmark(std::move(l)) {
	if (landmark) {
		landmarkName = landmark->getName();
	}
}

void AddLandmarkCommand::execute()
{
	territory.addLandmark(std::move(landmark));
}

void AddLandmarkCommand::undo()
{
	landmark = territory.removeLandmark(landmarkName);
}

std::string AddLandmarkCommand::description() const
{
	return "Add landmark: " + landmarkName;
}

RemoveLandmarkCommand::RemoveLandmarkCommand(Territory& t, const std::string& name) : territory(t), landmarkName(name), removedLandmark(nullptr) {}

void RemoveLandmarkCommand::execute()
{
	removedLandmark = territory.removeLandmark(landmarkName);
}

void RemoveLandmarkCommand::undo()
{
	territory.addLandmark(std::move(removedLandmark));
}

std::string RemoveLandmarkCommand::description() const
{
	return "Remove landmark: " + landmarkName;
}

std::string SetDangerLevelCommand::description() const
{
	return "Set danger level " + std::to_string(newLevel);
}

SetDangerLevelCommand::SetDangerLevelCommand(Territory& t, int level) : territory(t), oldLevel(1), newLevel(level) {
}
void SetDangerLevelCommand::execute()
{
	oldLevel = territory.getDangerLevel();
	territory.setDangerLevel(newLevel);
}

void SetDangerLevelCommand::undo()
{
	territory.setDangerLevel(oldLevel);
}