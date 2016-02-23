#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/SetAxlePosition.hpp"
#include "Commands/SetAxleMotion.hpp"
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
	m_ManipulatorStick.Button5.WhenPressed<SetAxleMotion<AxleMoveForward> >();
	m_ManipulatorStick.Button6.WhenPressed<SetAxleMotion<AxleMoveBackward> >();
	m_ManipulatorStick.Button7.WhenPressed<SetAxleMotion<AxleMoveStopped> >();
	m_ManipulatorStick.Button8.WhenPressed<SetAxlePosition<IntakePosition> >();
	m_ManipulatorStick.Button9.WhenPressed<SetAxlePosition<PortcullisUpPosition> >();
	m_ManipulatorStick.Button10.WhenPressed<SetAxlePosition<HoldPosition> >();

	m_ManipulatorStick.Trigger.WhenPressed<SetShooterMode<ShooterOn> >();
	m_ManipulatorStick.Button11.WhenPressed<SetShooterMode<ShooterOff> >();
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
