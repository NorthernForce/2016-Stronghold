#pragma once

#include "Commands/Command.h"
#include "../Main.h"


template<typename T>
class ExpelBall: public Command
{
	public:
		ExpelBall() :
			m_finished(false),
			m_point(0.0)

		{
			Requires(&Main::getIntake());
			Requires(&Main::getOpticalSensors());
			float m_point = Main::getOI().GetManipulatorStick().GetZ() + T::kValue;
			if (m_point > 1)
			{
				--m_point;
			}

			if (m_point < 0)
			{
				++m_point;
			}
		}

		virtual void Initialize()
		{
			Main::getIntake().Enable();
			m_finished = false;
			Main::getIntake().SetSetpoint(m_point); // 0.85, was 0.6, should be DefaultPosition::kDegrees
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
		float m_point;
};
