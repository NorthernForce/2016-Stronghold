#include "Shooter.h"

Shooter::Shooter() :
	SubsystemWithCommand<void>("Shooter"),
	m_shooterTalon(kShooterTalon)
{}

void Shooter::Forward()
{
	m_shooterTalon.Set(0.5, 0);
}

void Shooter::Stopped()
{
	m_shooterTalon.Set(0,0);
}

void Shooter::init()
{
	Stopped();
}
