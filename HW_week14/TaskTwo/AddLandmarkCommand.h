#pragma once
#include "Command.h"
#include "Territory.h"
#include <memory>

class AddLandmarkCommand : public Command
{
    Territory& target;
    std::unique_ptr<Landmark> landmark;
    std::string landmarkName;
public:
    AddLandmarkCommand(Territory& target, std::unique_ptr<Landmark> landmark);
    void execute() override;
    void undo() override;
    std::string description() const override;
};

