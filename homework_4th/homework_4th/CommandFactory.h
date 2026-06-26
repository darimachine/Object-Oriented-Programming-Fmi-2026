#pragma once
#include "Command.h"
#include <string>
#include "Territory.h"

class CommandFactory
{
	public:
		static std::unique_ptr<Command> create(const std::string& type, const std::string& args,
			Territory& territory);
};

