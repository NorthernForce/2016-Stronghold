#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class ExpelBall: public Command
{
	public:
		ExpelBall() :
			m_finished(false)

		{
			Requires(&Main::getIntake());
			Requires(&Main::getOpticalSensors());
		}

		virtual void Initialize()
		{
			Main::getIntake().Enable();
			m_finished = false;
			Main::getIntake().SetSetpoint(.28); //hack--need to change to a constant
		}

		virtual void Execute()
		{
			Main::getIntake().SetWheelForward();
			Main::getIntake().SetInternalBackward();

			Wait(3.5);
			m_finished = true;
		}


		virtual bool IsFinished()
		{
			return m_finished;
		}
		virtual void End()
		{
			Main::getIntake().SetWheelStopped();
			Main::getIntake().SetInternalStopped();
			Main::getIntake().Disable();
		}

		virtual void Interrupted()
		{
			Main::getIntake().SetWheelStopped();
			Main::getIntake().SetInternalStopped();
			Main::getIntake().Disable();
		}

	private:
		bool  m_finished;
};
