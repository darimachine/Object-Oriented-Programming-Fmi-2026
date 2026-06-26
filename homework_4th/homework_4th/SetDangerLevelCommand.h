#pragma once
#include "Command.h"
class SetDangerLevelCommand : public Command
{
	private:
		unsigned int dangerLevel;
		unsigned int previousDangerLevel = 0;

	public:
		SetDangerLevelCommand(Territory& context, unsigned int inpDangerLevel);
		void execute() override;
		void undo() override;
		std::string description() const override;
};

