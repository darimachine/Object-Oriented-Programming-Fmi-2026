#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "MyException.h"
#include "Landmark.h"
#include "Territory.h"
class Command
{
protected:
	std::vector<std::unique_ptr<Territory>> territories;
public:
	virtual void execute(Territory& t) = 0;
	virtual void undo(Territory& t) = 0;
	virtual std::string description(Territory& t) = 0;
	virtual void unexecute(Territory& t) = 0;
	
};

class AddLandmarkCommand : public Command {
private:
	std::unique_ptr<Landmark> l;
	std::unique_ptr<Landmark> lRedo=nullptr;
public:
	// Inherited via Command
	void undo(Territory& t) override;
	std::string description(Territory& t) override;

	// Inherited via Command
	void execute(Territory& t) override;
	AddLandmarkCommand(std::unique_ptr<Landmark> _l);

	// Inherited via Command
	void unexecute(Territory& t) override;
};
class RemoveLandmarkCommand : public Command {
private:
	std::unique_ptr<Landmark> l;
	std::unique_ptr<Landmark> lRedo = nullptr;
public:
	// Inherited via Command
	RemoveLandmarkCommand(std::unique_ptr<Landmark> _l);
	void execute(Territory& t) override;
	void undo(Territory& t) override;
	std::string description(Territory& t) override;

	// Inherited via Command
	void unexecute(Territory& t) override;
};
class SetDangerLevelCommand : public Command {
	int danger;
	int dangerRedo = -1;
public:


	// Inherited via Command
	void execute(Territory& t) override;
	SetDangerLevelCommand(int _danger) :danger(_danger) {};

	void undo(Territory& t) override;

	std::string description(Territory& t) override;


	// Inherited via Command
	void unexecute(Territory& t) override;

};

class CommandFactory {
public:
	static std::unique_ptr<Command> createCommand(std::string type, std::unique_ptr<Landmark> l = {}, int danger = 0) {
		if (type == "remove") {
			return std::make_unique<RemoveLandmarkCommand>(std::move(l));
		}
		if (type == "add") {
			return std::make_unique<AddLandmarkCommand>(std::move(l));
		}
		if (type == "set") {
			return std::make_unique<SetDangerLevelCommand>(danger);
		}
		return nullptr;
	}
};