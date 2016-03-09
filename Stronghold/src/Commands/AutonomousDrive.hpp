#pragma once

#include "Commands/Command.h"
#include "../Main.h"

class AutonomousDrive : public Command
{
public:
	AutonomousDrive(float speed, float distance, float angle) :
		m_duration(15), //length of autonomous
		m_speed(speed),
		m_distance(distance),
		m_angle(angle)
	{
		Requires(&Main::getDrive());
		Requires(&Main::getGyroSensor());
	}

	void Initialize() override
	{
		m_timer.Reset();
		m_timer.Start();
		Main::getGyroSensor().Zero();
		Main::getDrive().ResetRight();
		Main::getDrive().ResetLeft();
		Main::getDrive().DriveArcade(m_speed, 0.0, true);
	}

	void Execute() override
	{
		Main::getDrive().PutEncoderValues();

		if (Main::getDrive().GetLeftDistance() > m_distance) // Right encoder is currently giving strange values
		{
			Main::getDrive().DriveArcade(0.0, 0.0, true);
		}

		/*
		if (Main::getGyroSensor().GetAngle() > m_angle)
		{
			m_changeSpeedB = 0.0;
			Main::getDrive().DriveArcade(m_changeSpeedA, m_changeSpeedB, true);
		}
		*/
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
	const float m_speed;
	const float m_distance;
	const float m_angle;

	Timer m_timer;
};

