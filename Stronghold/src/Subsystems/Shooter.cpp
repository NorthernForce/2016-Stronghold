#include "Shooter.h"

Shooter::Shooter() :
	SubsystemWithCommand<void>("Shooter"),
	m_shooterTalon(kShooterTalon)
{}

void Shooter::Forward()
{
	m_shooterTalon.Set(1.0, 0);
}

void Shooter::Stopped()
{
	m_shooterTalon.Set(0,0);
}

void Shooter::init()
{
	Stopped();
}

float Shooter::GetVoltage()
{
	return m_shooterTalon.GetBusVoltage();
}

double Shooter::GetSpeed()
{
	return m_shooterTalon.GetSpeed();
}

bool Shooter::IsShooterReady()
{
	if (GetSpeed() > 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}
