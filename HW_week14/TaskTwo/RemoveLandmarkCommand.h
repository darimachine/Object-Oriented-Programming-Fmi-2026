#pragma once
#include "Command.h"
#include "Territory.h"
#include <memory>

class RemoveLandmarkCommand : public Command
{
    Territory& target;
    std::string landmarkName;
    std::unique_ptr<Landmark> removed;
public:
    RemoveLandmarkCommand(Territory& target, const std::string& name);
    void execute() override;
    void undo() override;
    std::string description() const override;
};

