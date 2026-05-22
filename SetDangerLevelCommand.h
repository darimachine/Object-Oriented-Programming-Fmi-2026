#pragma once
#include"Command.h"

class SetDangerLevelCommand:public Command
{
private:
	int newDangerLevel;
	int oldDangerLevel = 0;

public:
	SetDangerLevelCommand() = default;
	SetDangerLevelCommand(Territory& teritory, int newDangerLevel);

	void execute() override;
	void undo() override;
	string description() const override;
};

