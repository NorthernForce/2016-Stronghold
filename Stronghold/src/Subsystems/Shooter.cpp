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
	return m_shooterTalon.GetOutputVoltage();
}

double Shooter::GetCurrent()
{
	return m_shooterTalon.GetOutputCurrent();
}

bool Shooter::IsShooterReady()
{
	if (GetCurrent() > 4.1)
	{
		return true;
	}

	else
	{
		return false;
	}
}
