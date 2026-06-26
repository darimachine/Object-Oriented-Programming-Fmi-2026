#include "RemoveLandmarkCommand.h"
#include<iostream>

RemoveLandmarkCommand::RemoveLandmarkCommand(Territory& territory, unique_ptr<Landmark> landmark):
Command(territory),landmark(move(landmark)){}

void RemoveLandmarkCommand::execute()
{
    try
    {
        landmark = move(territory.removeLandmark(landmark->getName()));
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << '\n';
    }
}

void RemoveLandmarkCommand::undo()
{
    territory.addLandmark(move(landmark));
}

string RemoveLandmarkCommand::description() const
{
    return "Remove landmark " + landmark->getName();
}
