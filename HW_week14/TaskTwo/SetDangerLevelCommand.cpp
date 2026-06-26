#include "Utils.h"
#include "SetDangerLevelCommand.h"

SetDangerLevelCommand::SetDangerLevelCommand(Territory& target, int level) : target(target), newLevel(level), previousLevel(target.getDangerLevel())
{

}

void SetDangerLevelCommand::execute()
{
	previousLevel = target.getDangerLevel();
	target.setDangerLevel(newLevel);
}

void SetDangerLevelCommand::undo()
{
	target.setDangerLevel(previousLevel);
}

std::string SetDangerLevelCommand::description() const
{
	std::string result = "SetDangerLevel: ";
	result += target.getName();
	result += " -> ";
	result += formatDouble(newLevel);

	return result;
}

