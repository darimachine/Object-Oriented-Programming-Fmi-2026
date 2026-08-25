#pragma once
#include "Territory.h"


class Command
{
	
protected:

	Territory& territory;

public:

	Command() = default;
	Command(Territory& territory);

	virtual std::unique_ptr<Command> clone() = 0;

	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual std::string description() const = 0;
};

