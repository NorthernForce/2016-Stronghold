#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"


class Intake: public SubsystemWithCommand<void>
{
	private:

		CANTalon 		m_axleTalon;
		Talon 			m_wheelTalon;
		Encoder  		m_axleEnc;
		PIDController   m_pidLoop;

	public:
		Intake();
		float GetPID();
		void SetPID(float p, float i, float d);
		void SetSetpoint(float point);
		double GetEncoderValue();

};
