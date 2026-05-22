#include "CommandFactory.h"
#include"LandmarkFactory.h"
#include"AddLandmarkCommand.h"
#include"RemoveLandmarkCommand.h"
#include"SetDangerLevelCommand.h"
#include<stdexcept>
#include<sstream>

unique_ptr<Command> CommandFactory::createCommand(const string& type, const string& args, Territory& target)
{
    if (type == "add")
    {
        auto landmark = parseFromStingToLandMark(args);
        return make_unique <AddLandmarkCommand>(target, move(landmark));
    }
    else if (type == "remove")
    {
        auto landmark = parseFromStingToLandMark(args);
        return make_unique<RemoveLandmarkCommand>(target, move(landmark));
    }
    else if (type == "set")
    {
        return make_unique<SetDangerLevelCommand>(target, stoi(args));
    }

    throw invalid_argument("Invalid command type.");
}

unique_ptr<Landmark> CommandFactory::parseFromStingToLandMark(const string& s)
{
    istringstream ss(s);
    string landmarkType, name;
    double x, y;
    int threat;
    string extra;

    ss >> landmarkType >> name >> x >> y >> threat;
    ss >> ws;
    getline(ss, extra);

    return LandmarkFactory::create(landmarkType, name, Coordinates{ x,y }, threat, extra);
}
