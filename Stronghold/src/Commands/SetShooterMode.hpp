#pragma once

#include "Commands/Command.h"
#include "../Main.h"

enum ShooterMode
{
	ON,
	OFF
};

template<ShooterMode mode>
class SetShooterMode: public Command
{
	public:
		SetShooterMode(){}
		virtual void Initialize() {}
		virtual void Execute()
		{
			switch(mode)
			{
			case ON:
				Main::getShooter().Forward();
				break;
			case OFF:
				Main::getShooter().Stopped();
				break;
			}
		}

		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}
};
