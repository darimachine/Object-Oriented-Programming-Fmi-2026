#pragma once
#include "Territory.h"
class Command
{
	protected:
		Territory& context;

	public:
		Command( Territory& inpContext);
		virtual ~Command() = default;

		virtual void execute() = 0;
		virtual void undo() = 0;
		virtual std::string description() const = 0;
		
};

