#pragma once

#include "Commands/Command.h"
#include "WPILib.h"

class Auto: public Command
{
public:
	Auto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

