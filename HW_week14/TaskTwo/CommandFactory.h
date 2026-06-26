#pragma once
#include <memory>
#include "Command.h"
#include "Territory.h"
#include <memory>

class CommandFactory
{
public:
    static std::unique_ptr<Command> create(const std::string& type, const std::string& args, Territory& target);
    static std::string extractNextArgumentToken(const std::string& input, size_t& currentPosition);
    static double parseDoubleFromString(const std::string& numericString);
    static int parseIntegerFromString(const std::string& numericString);
};

