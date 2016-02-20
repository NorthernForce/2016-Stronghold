#pragma once

#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"


class Shooter: public SubsystemWithCommand<void>
{
	private:
		Talon 	m_shooterTalon;

	public:
		Shooter();
		void Forward();
		void Stopped();
		void init();
};
