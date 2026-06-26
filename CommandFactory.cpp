#include "CommandFactory.h"
#include "LandmarkFactory.h"
#include <iostream>
#include <string>
#include <vector>

std::unique_ptr<Command> CommandFactory::create(const std::string& type, const std::string& args, Territory& target)
{
    if (type == "add")
    {
        std::vector<std::string> words;
        std::string currentWord = "";

        for (int i = 0; i < args.length(); i++) {
            if (args[i] == ';') {
                words.push_back(currentWord);
                currentWord = ""; //clear
            }
            else {
                currentWord += args[i];
            }
        }
        //there isnt ; after the last word
        words.push_back(currentWord);

        std::string landmarkType = words[0];
        std::string name = words[1];
        std::string xStr = words[2];
        std::string yStr = words[3];
        std::string threatStr = words[4];
        std::string extra = words[5];

        //turn the text into double and int
        double x = std::stod(xStr);
        double y = std::stod(yStr);
        int threat = std::stoi(threatStr);
        Coords coords{ x, y };

        auto landmark = LandmarkFactory::create(landmarkType, name, coords, threat, extra);
        return std::make_unique<AddLandmarkCommand>(target, std::move(landmark));
    }
    else if (type == "remove")
    {
        return std::make_unique<RemoveLandmarkCommand>(target, args);
    }
    else if (type == "danger")
    {
        return std::make_unique<SetDangerLevelCommand>(target, std::stoi(args));
    }

    throw std::invalid_argument("Invalid command type!");
}