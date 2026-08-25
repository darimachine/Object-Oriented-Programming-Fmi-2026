#pragma once
#include "Command.h"

class AddLandmarkCommand : public Command
{
private:

	std::unique_ptr<Landmark> landmark;

public:

	AddLandmarkCommand() = default;
	AddLandmarkCommand(Territory& territory, std::unique_ptr<Landmark> landmark);

	virtual std::unique_ptr<Command> clone() override;

	void execute() override;
	void undo() override;
	std::string description() const override;
};

