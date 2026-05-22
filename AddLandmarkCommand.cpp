#include "AddLandmarkCommand.h"

AddLandmarkCommand::AddLandmarkCommand(Territory& territory, unique_ptr<Landmark> landmark,const string& landmarkName):
    Command(territory),landmark(move(landmark)),landmarkName(landmark->getName()){}

void AddLandmarkCommand::execute() 
{
    territory.addLandmark(move(landmark));
}

void AddLandmarkCommand::undo() 
{
    territory.removeLandmark(landmarkName);
}

string AddLandmarkCommand::description() const
{
    return "Add landmark " + landmarkName;
}
