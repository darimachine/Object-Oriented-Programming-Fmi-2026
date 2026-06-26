#pragma once
#include "Command.h"
class АddLandmarkCommand : public Command
{
	private:
		std::unique_ptr<Landmark> landmark;
		std::string landmarkName;

	public:
		АddLandmarkCommand(Territory& context, const std::string& inpLandmarkName);
		 void execute() override;
		 void undo() override;
		 std::string description() const override;
};

