#include "Intake.h"

Intake::Intake() :
	SubsystemWithCommand<void>("Intake"),
	m_axleTalon(kAxleTalon),
	m_wheelTalon(kWheelTalon),
	m_axleEnc(kChannelA, kChannelB, false, CounterBase::k4X),
	m_pidLoop(kP, kI, kD, &m_axleEnc, &m_axleTalon)
{}


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

void Intake::SetAxleForward()
{
	m_axleTalon.Set(0.5, 0);
}

void Intake::SetAxleBackward()
{
	m_axleTalon.Set(-0.5, 0);
}

void Intake::SetAxleStopped()
{
	m_axleTalon.Set(0,0);
}

void Intake::SetWheelForward()
{
	m_wheelTalon.SetSpeed(0.5);
}

void Intake::SetWheelBackward()
{
	m_wheelTalon.SetSpeed(-0.5);
}

void Intake::SetWheelStopped()
{
	m_wheelTalon.SetSpeed(0.0);
	//m_wheelTalon.Disable();
	m_wheelTalon.StopMotor();
}

void Intake::init()
{
	m_wheelTalon.SetSpeed(0.0);
	//m_axleTalon.StopMotor();
	//m_wheelTalon.Disable();
	//m_wheelTalon.EnableDeadbandElimination(true);
	//m_axleEnc.SetPIDSourceType(PIDSourceType::kDisplacement);
	//m_pidLoop.SetOutputRange(-0.5, 0.5);

}
