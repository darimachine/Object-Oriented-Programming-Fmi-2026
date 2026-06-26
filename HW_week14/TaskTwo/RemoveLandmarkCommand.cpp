#include "RemoveLandmarkCommand.h"

RemoveLandmarkCommand::RemoveLandmarkCommand(Territory& target, const std::string& name) : target(target), landmarkName(name)
{

}

void RemoveLandmarkCommand::execute()
{
	removed = target.removeLandmark(landmarkName);
}

void RemoveLandmarkCommand::undo()
{
	if (removed)
	{
		target.addLandmark(removed->clone());
	}
}

std::string RemoveLandmarkCommand::description() const
{
	return "RemoveLandmark: " + landmarkName + " <- " + target.getName();
}

