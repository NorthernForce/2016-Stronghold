#include "DriveWithJoystick.h"
#include "Main.h"

DriveWithJoystick::DriveWithJoystick()
{
	Requires(&Main::getDrive());
}

// Called just before this Command runs the first time
void DriveWithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	float x = Main::getOI().GetDriverStick().GetLeftStickX();
	float y = Main::getOI().GetDriverStick().GetLeftStickY();
	bool z = true;

	Main::getDrive().DriveArcade(x, y, z);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveWithJoystick::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoystick::Interrupted()
{

}
