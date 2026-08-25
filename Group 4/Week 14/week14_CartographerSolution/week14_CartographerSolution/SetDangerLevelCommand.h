#pragma once
#include "Command.h"

class SetDangerLevelCommand : public Command
{
private:

	bool settingDangerLevelForTheFirstTime = true;
	short dangerLevel = -1;
	short oldDangerLevel = -1;

public:

	SetDangerLevelCommand() = default;
	SetDangerLevelCommand(Territory& territory, short dangerLevel);

	virtual std::unique_ptr<Command> clone() override;

	void execute() override;
	void undo() override;
	std::string description() const override;
};

