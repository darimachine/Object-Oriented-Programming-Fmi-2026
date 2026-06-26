#pragma once
#include"Command.h"

class RemoveLandmarkCommand:public Command
{
private:
	unique_ptr<Landmark> landmark;

public:
	RemoveLandmarkCommand() = default;
	RemoveLandmarkCommand(Territory& territory, unique_ptr<Landmark> landmark);

	void execute() override;
	void undo() override;
	string description() const override;
};

