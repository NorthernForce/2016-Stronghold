#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/SetAxlePosition.hpp"
#include "Commands/SetAxleMotion.hpp"
#include "Commands/SetShooterMode.hpp"
#include "Commands/IntakeBall.hpp"
#include "Commands/ShootBall.hpp"
#include "Commands/ExpelBall.hpp"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort),
	m_XBoxManipulatorStick(kXBoxManipulatorPort) {}

void OI::init()
{
	m_DriverStick.RightBumper.WhenPressed<SetDriveMode<DriveModeFlipped> > ();
	m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<DriveModeRegular> > ();

	m_ManipulatorStick.Button4.ToggleWhenPressed<SetIntakeMode<IntakeForward> >();
	m_ManipulatorStick.Button4.ToggleWhenPressed<SetIntakeMode<IntakeStopped> >();

	m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<IntakeBackward> >();
	m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<IntakeStopped> >();

	m_ManipulatorStick.Button6.WhenPressed<IntakeBall> ();
	m_ManipulatorStick.Button3.WhenPressed<ShootBall> ();
	m_ManipulatorStick.Trigger.WhenPressed<ExpelBall> ();

	m_ManipulatorStick.Button8.WhenPressed<SetAxlePosition<DefaultPosition> >();
	m_ManipulatorStick.Button9.WhenPressed<SetAxlePosition<UpPosition> >();
	m_ManipulatorStick.Button10.WhenPressed<SetAxlePosition<DownPosition> >();

	m_ManipulatorStick.Button2.ToggleWhenPressed<SetShooterMode<ShooterOn> >();
	m_ManipulatorStick.Button2.ToggleWhenPressed<SetShooterMode<ShooterOff> >();
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
