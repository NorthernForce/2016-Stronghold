#pragma once

#include "Commands/Command.h"
#include "../Main.h"


template<typename T>
class SetAxlePosition: public Command
{
	public:
		SetAxlePosition() :
			m_finished(false)
		{
			Requires(&Main::getIntake());
		}
		virtual void Initialize()
		{
			Main::getIntake().Enable();
			Main::getIntake().SetSetpoint(T::kValue);
			m_finished = false;
		}

		virtual void Execute()
		{
			m_finished = Main::getIntake().OnTarget();

		}



		virtual bool IsFinished() { return m_finished; }
		virtual void End()
		{
			Main::getIntake().Disable();
		}

		virtual void Interrupted()
		{
			Main::getIntake().Disable();
		}

	private:
		bool  m_finished;
};
