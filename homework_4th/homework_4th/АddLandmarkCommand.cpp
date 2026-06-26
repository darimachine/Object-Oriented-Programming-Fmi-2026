#include "АddLandmarkCommand.h"

АddLandmarkCommand::АddLandmarkCommand(Territory& context, const std::string& inpLandmarkName):
	Command(context), landmarkName(inpLandmarkName), landmark(nullptr)
{
	if (landmark)
	{
		landmarkName = landmark->getName();
	}
}

void АddLandmarkCommand::execute()
{
	if (landmark)
	{
		context.addLandmark(std::move(landmark));
	}
}

void АddLandmarkCommand::undo()
{
	landmark = context.removeLandmark(landmarkName);
}

std::string АddLandmarkCommand::description() const
{
	return "Added landmark: " + landmarkName;
}
