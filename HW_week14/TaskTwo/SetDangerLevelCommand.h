#pragma once
#include "Command.h"
#include "Territory.h"
#include <memory>

class SetDangerLevelCommand : public Command
{
    Territory& target;
    int newLevel;
    int previousLevel;
public:
    SetDangerLevelCommand(Territory& target, int level);
    void execute() override;
    void undo() override;
    std::string description() const override;
};

