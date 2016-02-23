#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"


class Intake: public PIDSubsystem
{
	private:

		Talon 					m_axleTalon;
		Talon 					m_wheelTalon;
		AnalogPotentiometer     m_axleEnc;
//		PIDController 			m_pidLoop;
//		float 					m_degrees;

	protected:
		double ReturnPIDInput();
		void UsePIDOutput(double output);

	public:
		Intake();
	//	float GetPID();
	//	void SetPID(float p, float i, float d);
	//	void SetSetpoint(float point);
	//	double GetEncoderValue();

	//	static float ConvertToDegrees(float voltage);

		void SetAxleForward();
		void SetAxleBackward();
		void SetAxleStopped();
		void SetWheelForward();
		void SetWheelBackward();
		void SetWheelStopped();
		void init();

};
