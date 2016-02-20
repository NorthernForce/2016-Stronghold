#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/SetAxlePosition.hpp"
#include "Commands/SetShooterMode.hpp"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort),
	m_XBoxManipulatorStick(kXBoxManipulatorPort) {}

void OI::init()
{
	m_DriverStick.RightBumper.WhenPressed<SetDriveMode<DriveModeFlipped> > (); //actually y
	m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<DriveModeRegular> > (); //actually left

	m_ManipulatorStick.Button2.WhenPressed<SetIntakeMode<IntakeForward> >();
	m_ManipulatorStick.Button3.WhenPressed<SetIntakeMode<IntakeBackward> >();
	m_ManipulatorStick.Button4.WhenPressed<SetIntakeMode<IntakeStopped> >();
	m_ManipulatorStick.Button5.WhenPressed<SetAxlePosition<MOVEFORWARD> >();
	m_ManipulatorStick.Button6.WhenPressed<SetAxlePosition<MOVESTOPPED> >();
	m_ManipulatorStick.Button7.WhenPressed<SetAxlePosition<MOVEBACKWARD> >();
	m_ManipulatorStick.Button8.WhenPressed<SetShooterMode<ON> >();
	//m_ManipulatorStick.Button9.WhenPressed<SetShooterMode<OFF> >();
}

FRCXboxJoystick& OI::GetDriverStick()
{
    return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}

FRCXboxJoystick& OI::GetXBoxManipulatorStick()
{
	return m_XBoxManipulatorStick;
}
