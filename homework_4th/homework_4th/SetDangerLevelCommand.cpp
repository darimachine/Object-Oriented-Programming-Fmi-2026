#include "SetDangerLevelCommand.h"
#include <stdexcept>
#include <string>

SetDangerLevelCommand::SetDangerLevelCommand(Territory& context, unsigned int inpDangerLevel):
	Command(context), dangerLevel(inpDangerLevel)
{
	if(dangerLevel > MAX_DANGEER)
	{
		throw std::invalid_argument("The danger level can not be more than 10");
	}
}

void SetDangerLevelCommand::execute()
{
	previousDangerLevel = context.getDangerLevel();
	context.setDangerLever(dangerLevel);
}

void SetDangerLevelCommand::undo()
{
	context.setDangerLever(previousDangerLevel);
}

std::string SetDangerLevelCommand::description() const
{
	return "Danger level was changed to: " + std::to_string(dangerLevel);
}
