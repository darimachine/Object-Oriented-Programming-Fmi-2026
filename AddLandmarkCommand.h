#pragma once
#include"Command.h"

class AddLandmarkCommand :public Command
{
private:
	string landmarkName;
	unique_ptr<Landmark> landmark;

public:
	AddLandmarkCommand() = default;
	AddLandmarkCommand(Territory& territory, unique_ptr<Landmark> landmark, const string& landmarkName);

	void execute()  override;
	void undo()  override;
	string description() const override;
};

