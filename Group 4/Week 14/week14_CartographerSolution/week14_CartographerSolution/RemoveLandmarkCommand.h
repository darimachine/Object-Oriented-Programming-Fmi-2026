#pragma once
#include "Command.h"

class RemoveLandmarkCommand : public Command
{
private:

	std::string landmarkToRemove;
	std::unique_ptr<Landmark> landmark;

public:

	RemoveLandmarkCommand() = default;
	RemoveLandmarkCommand(Territory& territory, std::string landmarkName);

	virtual std::unique_ptr<Command> clone() override;

	void execute() override;
	void undo() override;
	std::string description() const override;
};

