#pragma once
#include"Territory.h"

class Command
{
protected:
	Territory& territory;

public:
	Command() = default;
	explicit Command(Territory& territory);

	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual string description()const = 0;
	virtual ~Command() = default;
};

