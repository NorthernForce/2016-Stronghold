#pragma once

#include "Commands/Command.h"
#include "../Main.h"

class AutonomousDrive : public Command
{
public:
	AutonomousDrive(float duration, float x, float y) :
		m_duration(duration),
		m_x(x),
		m_y(y)
	{
		Requires(&Main::getDrive());
	}

	void Initialize() override
	{
		m_timer.Reset();
		m_timer.Start();
	}

	void Execute() override
	{
		Main::getDrive().DriveArcade(m_x, m_y, true);
	}

	bool IsFinished() override
	{
		return m_timer.HasPeriodPassed(m_duration);
	}

	void End() override
	{
		Main::getDrive().DriveArcade(0, 0, true);
	}

	void Interrupted() override
	{
		Main::getDrive().DriveArcade(0, 0, true);
	}

private:
	const double m_duration;
	const float m_x;
	const float m_y;
	Timer m_timer;
};

