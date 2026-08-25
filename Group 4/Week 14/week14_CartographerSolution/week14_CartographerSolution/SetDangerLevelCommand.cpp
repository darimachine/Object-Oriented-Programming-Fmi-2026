#include "SetDangerLevelCommand.h"

SetDangerLevelCommand::SetDangerLevelCommand(Territory& territory, short dangerLevel) :
	Command(territory), dangerLevel(dangerLevel)
{
}

std::unique_ptr<Command> SetDangerLevelCommand::clone()
{
	return std::unique_ptr<SetDangerLevelCommand>(this);
}

void SetDangerLevelCommand::execute()
{
	oldDangerLevel = territory.getDangerLevel();
	territory.setDangetLevel(dangerLevel);
}

void SetDangerLevelCommand::undo()
{
	territory.setDangetLevel(oldDangerLevel);
}

std::string SetDangerLevelCommand::description() const
{
	return std::move(std::string("This commands sets a danger level to all landmarks in the territory"));
}
