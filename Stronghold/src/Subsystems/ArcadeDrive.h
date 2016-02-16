#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "Commands/DriveWithJoystick.h"
#include "WPILib.h"


class ArcadeDrive: public SubsystemWithCommand<DriveWithJoystick>
{
private:

	RobotDrive m_drive;

	CANTalon m_frontLeft;
	CANTalon m_frontRight;
	CANTalon m_backLeft;
	CANTalon m_backRight;

	double P;
	double I;
	double D;


public:
	ArcadeDrive();
	void InitDefaultCommand();
	void DriveArcade(float x, float y, bool z);
	void init();
	void EnableEncoders(bool invertGains = true);
	void DisableEncoders();
};

