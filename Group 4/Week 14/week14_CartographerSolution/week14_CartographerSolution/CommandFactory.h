#pragma once
#include "Command.h"

class CommandFactory
{
    static std::unique_ptr<Command> create(
        const std::string& type,
        const std::string& args,
        Territory& target
    );
};

