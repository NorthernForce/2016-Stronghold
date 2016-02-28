#pragma once

#include "Commands/Command.h"
#include "../Main.h"


class ShootBall: public Command
{
	public:
		ShootBall() :
			m_finished(false)
		{
			Requires(&Main::getShooter());
			Requires(&Main::getIntake());
			Requires(&Main::getOpticalSensors());
		}

		virtual void Initialize()
		{
			m_finished = false;
		}

		virtual void Execute()
		{
			Main::getShooter().Forward();
			Wait(4.0);
			Main::getIntake().SetInternalForward();
			Wait(4.0);
			m_finished = true;
		}


		virtual bool IsFinished() { return m_finished; }
		virtual void End()
		{
			Main::getShooter().Stopped();
			Main::getIntake().SetInternalStopped();
		}

		virtual void Interrupted()
		{
			Main::getShooter().Stopped();
			Main::getIntake().SetInternalStopped();
		}

	private:
		bool  m_finished;
};
