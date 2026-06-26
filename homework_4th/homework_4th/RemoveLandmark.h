#pragma once
#include "Command.h"
#include <memory>
#include "Territory.h"
class RemoveLandmark : public Command
{
	private:
		std::unique_ptr<Landmark> landmark;
		std::string landmarkName;

	public:
		RemoveLandmark(Territory& context, const std::string& inpLandmark);
		void execute() override;
		void undo() override;
		std::string description() const override;
};

