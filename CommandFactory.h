#pragma once
#include"Command.h"

class CommandFactory
{
public:
	static unique_ptr<Command> createCommand(const string& type, const string& args, Territory& target);
	static unique_ptr<Landmark> parseFromStingToLandMark(const string& s);
};

