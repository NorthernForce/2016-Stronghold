#pragma once

#include "Commands/Command.h"
#include "../Main.h"

enum AxlePosition
{
	FEED,
	PUSH,
	HOLD,
	MOVEFORWARD,
	MOVEBACKWARD,
	MOVESTOPPED,
};

template<AxlePosition mode>
class SetAxlePosition: public Command
{
	public:
		SetAxlePosition(){}
		virtual void Initialize(){}
		virtual void Execute()
		{
			switch(mode)
			{
			case FEED:
				Main::getIntake().SetSetpoint(1);
				break;
			case PUSH:
				Main::getIntake().SetSetpoint(2);
				break;
			case HOLD:
				Main::getIntake().SetSetpoint(3);
				break;
			case MOVEFORWARD:
				Main::getIntake().SetAxleForward();
				break;
			case MOVEBACKWARD:
				Main::getIntake().SetAxleBackward();
				break;
			case MOVESTOPPED:
				Main::getIntake().SetAxleStopped();
				break;
			}
		}

		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}
};
