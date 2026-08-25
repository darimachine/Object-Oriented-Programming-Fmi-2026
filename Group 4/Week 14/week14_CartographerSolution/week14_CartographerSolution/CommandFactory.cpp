#include "CommandFactory.h"
#include "LandmarkFactory.h"
#include "AddLandmarkCommand.h"
#include "RemoveLandmarkCommand.h"
#include "SetDangerLevelCommand.h"

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

std::unique_ptr<Command> CommandFactory::create(
    const std::string& type, 
    const std::string& args, 
    Territory& target)
{
    
    if (type == "add")
    {
        try {
            std::vector<std::string> arguments;
            std::string current;
            std::stringstream argsStream (args);

            while (std::getline(argsStream, current, ';'))
            {
                arguments.push_back(current);
            }

            Coordinates tempCoordinates(std::stod(arguments[2]), std::stod(arguments[3]));

            std::unique_ptr<Landmark> temp = LandmarkFactory::create(arguments[0], arguments[1],
                tempCoordinates, std::stoi(arguments[4]), arguments[5]);

            return std::make_unique<AddLandmarkCommand>(target, std::move(temp));
        }
        catch (std::exception& ex)
        {
            std::cout << "Cannot add a landmark with the given parameters" << std::endl;
            std::cout << ex.what() << std::endl;

            return nullptr;
        }
        catch (...)
        {
            std::cout << "Something went really wrong" << std::endl;
            return nullptr;
        }
    }
    if (type == "remove")
    {
        return std::make_unique<RemoveLandmarkCommand>(target, args);
    }
    if (type == "danger")
    {
        return std::make_unique<SetDangerLevelCommand>(target, std::stoi(args));
    }

    throw std::invalid_argument("There isn't a command of such type");
}
