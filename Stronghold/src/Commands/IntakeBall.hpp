#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class IntakeBall: public CommandGroup
{
	public:
		IntakeBall()
		{
			AddParallel(new SetAxlePosition<IntakePosition>);
			AddParallel(new SetIntakeMode<IntakeForward>);
		}
};

//Intake Mode will need to be manually set back to stopped.
