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
			//Main::getIntake().Enable();
			m_finished = false;
			//Main::getIntake().SetSetpoint(0.85); // was 0.6, should be DefaultPosition::kDegrees
		}

		virtual void Execute()
		{
			//Main::getIntake().SetWheelForward();
			Main::getIntake().SetInternalBackward(1.0);


			m_finished = Main::getOpticalSensors().GetSensorBack();
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
