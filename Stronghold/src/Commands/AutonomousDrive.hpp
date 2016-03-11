#pragma once

#include "Commands/Command.h"
#include "../Main.h"
#include "../RobotMap.h"

class DriveStraight{};
class DriveTurn{};

template<class Mode>
class AutonomousDrive : public Command
{
public:
	AutonomousDrive(float duration, float speed, float distance, float angle) :
		m_duration(duration),
		m_speed(speed),
		m_distance(distance),
		m_angle(angle),
		m_initialAngle(0)
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
		m_initialAngle = Main::getGyroSensor().GetAngle();

		Main::getDrive().SetDistancePerPulse();

		specificInit(Mode());
	}

	void specificInit(const DriveStraight& mode)
	{
		Main::getDrive().DriveArcade(m_speed, 0.0, true);
	}

	void specificInit(const DriveTurn& mode)
	{
		Main::getDrive().DriveArcade(0.0, -m_speed, true);
	}

	void Execute() override
	{
		Main::getDrive().PutEncoderValues();

		specificExecute(Mode());

	}

	void specificExecute(const DriveStraight& mode)
	{
		if (Main::getDrive().GetLeftDistance() > m_distance) // Right encoder is currently giving strange values
		{
			Main::getDrive().DriveArcade(0.0, 0.0, true);
		}
	}

	void specificExecute(const DriveTurn& mode)
	{
		if (Main::getGyroSensor().GetAngle() - m_initialAngle > m_angle)
		{
			Main::getDrive().DriveArcade(0.0, 0.0, true);
		}
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
	float m_initialAngle;

	Timer m_timer;
};

