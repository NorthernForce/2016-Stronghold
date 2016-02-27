#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"

class GyroSensor: public SubsystemWithCommand<void>
{
	public:

		GyroSensor();
		float GetGyroAngle();

	private:
		AnalogGyro m_gyro;

};
