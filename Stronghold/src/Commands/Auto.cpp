#include "Auto.h"
#include "Main.h"

Auto::Auto(){}

void Auto::Initialize()
{
	Requires(&Main::getDrive());
	Requires(&Main::getIntake());
	Requires(&Main::getShooter());
	Requires(&Main::getGyroSensor());
}

void Auto::Execute()
{
	while(Main::getGyroSensor().GetDisplacement() < 10)
	{
		Main::getDrive().DriveArcade(0.8, 0.0, false);
	}

	while(Main::getGyroSensor().GetDisplacement() > 10 && Main::getGyroSensor().GetAngle() < 20)
	{
		Main::getDrive().DriveArcade(0.0, 0.2, false);
	}

	while(Main::getGyroSensor().GetAngle() > 20)
	{
		Main::getShooter().Forward();
		Wait(4.0);
		Main::getShooter().Stopped();
	}
}

bool Auto::IsFinished() { return false; }

void Auto::End()
{
	Main::getShooter().Stopped();
}

void Auto::Interrupted() {}


/*
 * Low bar start: go under, turn, shoot
 * Middle start: drive forward, turn, go under low bar, turn, shoot
 * Spy start: position, shoot
 */
