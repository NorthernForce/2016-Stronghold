#include "Intake.h"

Intake::Intake() :
	SubsystemWithCommand<void>("Intake"),
	m_axleTalon(kAxleTalon),
	m_wheelTalon(kWheelTalon),
	m_axleEnc(kChannelA, kChannelB, false, CounterBase::k4X),
	m_pidLoop(kP, kI, kD, &m_axleEnc, &m_axleTalon)
{
}

float Intake::GetPID()
{
	return m_pidLoop.Get();
}

void Intake::SetPID(float p, float i, float d)
{
	m_pidLoop.SetPID(p, i, d);
}

void Intake::SetSetpoint(float point)
{
	m_pidLoop.SetSetpoint(point);
}

double Intake::GetEncoderValue()
{
	return m_axleEnc.Get();
}
