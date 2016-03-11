#include "Flashlight.h"
#include "../RobotMap.h"

Flashlight::Flashlight() :
		Subsystem("ExampleSubsystem"),
		m_relay(kFlashlightPort) {}

void Flashlight ::TurnOn()
{
	m_relay.Set(Relay::kOn);
}

void Flashlight::TurnOff()
{
	m_relay.Set(Relay::kOff);
}
