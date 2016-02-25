#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class ShootBall: public CommandGroup
{
	public:
		ShootBall()
		{
			AddSequential(new SetShooterMode<ShooterOn>);
			AddSequential(new SetIntakeMode<IntakeForward>);
		}
};
