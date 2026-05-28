#pragma once
#include <memory>
#include <sstream>
#include "Command.h"
#include "LandmarkFactory.h"

class CommandFactory {
public:
    static std::unique_ptr<Command> create(
        const std::string& type,
        const std::string& args,
        Territory& target
    ) {
        std::stringstream ss(args);
        if (type == "add") {
            std::string lType, name, extra;
            double x, y;
            int threat;
            ss >> lType >> name >> x >> y >> threat;
            std::getline(ss >> std::ws, extra);

            auto landmark = LandmarkFactory::create(lType, name, Coords{ x, y }, threat, extra);
            return std::make_unique<AddLandmarkCommand>(target, std::move(landmark), name);
        }
        else if (type == "remove") {
            std::string name;
            ss >> name;
            return std::make_unique<RemoveLandmarkCommand>(target, name);
        }
        else if (type == "danger") {
            int level;
            ss >> level;
            return std::make_unique<SetDangerLevelCommand>(target, level);
        }

        throw std::invalid_argument("Unknown command type: " + type);
    }
};
