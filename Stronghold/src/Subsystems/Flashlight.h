#pragma once
#include "Subsystems/SubsystemWithCommand.hpp"
#include "WPILib.h"
#include "RobotMap.h"

class Flashlight: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay m_relay;
public:
	Flashlight();
	void TurnOn();
	void TurnOff();
};

