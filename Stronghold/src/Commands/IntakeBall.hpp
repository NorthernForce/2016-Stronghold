#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class IntakeBall: public Command
{
	public:
		IntakeBall() :
			m_finished(false)
		{
			Requires(&Main::getIntake());
			Requires(&Main::getOpticalSensors());
		}

		virtual void Initialize()
		{
			m_finished = false;
			Main::getIntake().SetSetpoint(100/360); //hack--need to change to a constant
		}

		virtual void Execute()
		{
			Main::getIntake().SetWheelForward();
			Main::getIntake().SetInternalForward();

			if (Main::getOpticalSensors().GetSensorBack() == 0)
			{
				Main::getIntake().SetWheelStopped();
				Main::getIntake().SetInternalStopped();
			}

			m_finished = true;

		}


		virtual bool IsFinished() { return m_finished; }
		virtual void End() {}
		virtual void Interrupted() {}

	private:
		bool  m_finished;
};
