#include "RemoveLandmarkCommand.h"

RemoveLandmarkCommand::RemoveLandmarkCommand(Territory& territory, std::string landmarkName) :
    Command(territory), landmarkToRemove(landmarkName)
{
}

std::unique_ptr<Command> RemoveLandmarkCommand::clone()
{
    return std::unique_ptr<RemoveLandmarkCommand>(this);
}

void RemoveLandmarkCommand::execute()
{
    landmark = std::move(territory.removeLandmark(landmarkToRemove));
}

void RemoveLandmarkCommand::undo()
{
    territory.addLandmark(std::move(landmark));
}

std::string RemoveLandmarkCommand::description() const
{
    return std::move(std::string("This commands removes a landmark from the territory"));
}
