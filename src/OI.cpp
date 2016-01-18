#include "OI.h"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort),
	m_XBoxManipulatorStick(kXBoxManipulatorPort) {}

void OI::init()
{
	// Process operator interface input here.
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
