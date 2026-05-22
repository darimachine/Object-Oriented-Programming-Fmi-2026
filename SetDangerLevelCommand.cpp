#include "SetDangerLevelCommand.h"
#include<stdexcept>
#include<iostream>

SetDangerLevelCommand::SetDangerLevelCommand(Territory& territory,int newDangerLevel):
    Command(territory),newDangerLevel(newDangerLevel){ }

void SetDangerLevelCommand::execute()
{
    try
    { 
        oldDangerLevel = territory.getDangerlevel();
        territory.setDangerLevel(newDangerLevel);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << '\n';
    }
}

void SetDangerLevelCommand::undo()
{
    try
    {
        territory.setDangerLevel(oldDangerLevel);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << '\n';
    }
}

string SetDangerLevelCommand::description() const
{
    return "Danger level set from " + to_string(oldDangerLevel) + 
        " to " + to_string(newDangerLevel);
}
