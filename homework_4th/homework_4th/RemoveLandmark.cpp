#include "RemoveLandmark.h"

RemoveLandmark::RemoveLandmark(Territory& context, const std::string& inpLandmark):
	Command(context), landmarkName(inpLandmark), landmark(nullptr)
{
}

void RemoveLandmark::execute()
{

	landmark = context.removeLandmark(landmarkName);
}

void RemoveLandmark::undo()
{
	if (landmark)
	{
		context.addLandmark(std::move(landmark));
	}
}

std::string RemoveLandmark::description() const
{
	return "Landmark: " + landmarkName + " was removed";
}
