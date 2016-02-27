#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"


class Intake: public PIDSubsystem
{
	private:

		CANTalon 				m_axleTalon;
		Talon 					m_wheelTalon;
		CANTalon				m_internalTalon;
		AnalogPotentiometer     m_axleEnc;

	protected:
		double ReturnPIDInput();
		void UsePIDOutput(double output);

	public:
		Intake();

		void SetAxleForward();
		void SetAxleBackward();
		void SetAxleStopped();
		void SetWheelForward();
		void SetWheelBackward();
		void SetWheelStopped();
		void SetInternalForward();
		void SetInternalBackward();
		void SetInternalStopped();
		void init();

};
