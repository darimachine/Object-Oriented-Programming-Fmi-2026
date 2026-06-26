#include "Command.h"
#include "Territory.h"
#include "Landmark.h"
void AddLandmarkCommand::undo(Territory& t)
{
    for (const auto& i : territories) {
        execute(t);
        break;
    }
}

std::string AddLandmarkCommand::description(Territory& t)
{
    return "removed landmark " + l->getName();
}

void AddLandmarkCommand::execute(Territory& t)
{
    lRedo = std::move(l);
    t.removeLandmark(lRedo->getName());
}

AddLandmarkCommand::AddLandmarkCommand(std::unique_ptr<Landmark> _l)
{
    l = std::move(_l);
}

void AddLandmarkCommand::unexecute(Territory& t)
{
    if (lRedo) {
        l = std::move(lRedo);
        t.addLandmark(l->clone());
    }
}

RemoveLandmarkCommand::RemoveLandmarkCommand(std::unique_ptr<Landmark> _l)
{
    l = std::move(_l);
}

void RemoveLandmarkCommand::execute(Territory& t)
{
    lRedo = std::move(l);
    t.addLandmark(lRedo->clone());
}

void RemoveLandmarkCommand::undo(Territory& t)
{
    execute(t);
}

std::string RemoveLandmarkCommand::description(Territory& t)
{
    return "The landmark " + lRedo->getName() + " is added back";
}

void RemoveLandmarkCommand::unexecute(Territory& t)
{
    if (lRedo) {
        l = std::move(lRedo);
        t.removeLandmark(l->getName());
    }
}

void SetDangerLevelCommand::execute(Territory& t)
{
    dangerRedo = danger;
    t.setDangerLevel(danger);
}

void SetDangerLevelCommand::undo(Territory& t)
{
    execute(t);
}

std::string SetDangerLevelCommand::description(Territory& t)
{
    return "The danger is back to before value";
}

void SetDangerLevelCommand::unexecute(Territory& t)
{
    if (dangerRedo != -1) {
        t.setDangerLevel(dangerRedo);
        danger = dangerRedo;
    }
}
