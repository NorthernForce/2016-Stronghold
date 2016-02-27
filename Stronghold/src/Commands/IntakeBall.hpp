#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class IntakeBall: public Command
{
	public:
		IntakeBall() :
			m_finished(false),
			m_axleMove(true)
		{
			Requires(&Main::getIntake());
			Requires(&Main::getOpticalSensors());
		}

		virtual void Initialize()
		{
			Main::getIntake().Enable();
			m_finished = false;
			Main::getIntake().SetSetpoint(0.6); //hack--need to change to a constant
		}

		virtual void Execute()
		{
			if (m_axleMove)
			{
				Main::getIntake().SetWheelBackward();
			}

			Main::getIntake().SetInternalForward();

			if (Main::getOpticalSensors().GetSensorBack() == 0)
			{
				Main::getIntake().SetWheelSlow();
				m_axleMove = false;
			}

			if (Main::getOpticalSensors().GetSensorFront() == 0)
			{
				Main::getIntake().SetInternalStopped();
				Main::getIntake().SetWheelStopped();
				m_finished = true;
			}
		}


		virtual bool IsFinished()
		{
			m_finished = Main::getOpticalSensors().GetSensorFront() == 0;

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
		bool  m_axleMove;
};
