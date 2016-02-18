#pragma once

#include "Commands/Command.h"
#include "../Main.h"

enum DriveMode
{
	ENCODERS_ON,
	ENCODERS_OFF,
};

template<DriveMode mode>
class SetDriveMode: public Command
{
	public:
		SetDriveMode(){}
		virtual void Initialize()
		{
			switch(mode)
			{
			case ENCODERS_ON:
				Main::getDrive().EnableEncoders(true);
				break;
			case ENCODERS_OFF:
				Main::getDrive().DisableEncoders();
				break;
			}
		}

		virtual void Execute() {}
		virtual bool IsFinished() { return true; }
		virtual void End() {}
		virtual void Interrupted() {}
};
