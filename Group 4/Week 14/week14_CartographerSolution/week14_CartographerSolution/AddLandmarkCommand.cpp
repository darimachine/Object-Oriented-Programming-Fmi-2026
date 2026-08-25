#include "AddLandmarkCommand.h"

AddLandmarkCommand::AddLandmarkCommand(Territory& territory, std::unique_ptr<Landmark> landmark) :
    Command(territory), landmark(std::move(landmark))
{
}

std::unique_ptr<Command> AddLandmarkCommand::clone()
{
    return std::unique_ptr<AddLandmarkCommand>(this);
}

void AddLandmarkCommand::execute()
{

    territory.addLandmark(landmark->clone());
}

void AddLandmarkCommand::undo()
{

    territory.removeLandmark(landmark->getName());
}

std::string AddLandmarkCommand::description() const
{
    return std::move(std::string("This commands add a landmark to the territory"));
}
