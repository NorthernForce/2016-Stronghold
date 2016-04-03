#pragma once

#include <WPILib.h>
//#include "../Commands/RangeReadout.h"
#include "SubsystemWithCommand.hpp"


class UltrasonicSensor: public SubsystemWithCommand<void>
{
	public:

		UltrasonicSensor(int analogChannel, int serialChannel, int onChannel);

		double GetRangeInInches() const;

	private:

		const float kMinVoltage;
		const float kVoltageRange;
		const float kMinDistance;
		const float kDistanceRange;
		mutable AnalogInput m_distanceChannel;

		DigitalOutput m_serialMode;

		DigitalOutput m_sensorOn;
};



