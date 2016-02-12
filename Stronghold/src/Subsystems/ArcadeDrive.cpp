#include "ArcadeDrive.h"
#include "../RobotMap.h"

ArcadeDrive::ArcadeDrive() :
		SubsystemWithCommand<DriveWithJoystick>("ArcadeDrive"),
		m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight),
		m_frontLeft(kFrontLeftTalon),
		m_frontRight(kFrontRightTalon),
		m_backLeft(kBackLeftTalon),
		m_backRight(kBackRightTalon),
		P(0),
		I(0),
		D(0)
{
	m_drive.SetSafetyEnabled(false);
}

void ArcadeDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ArcadeDrive::DriveArcade(float x, float y, bool z)
{
	m_drive.ArcadeDrive(x, y, z);
}

void ArcadeDrive::init()
{
	m_drive.SetSafetyEnabled(false);
	m_drive.SetExpiration(0.2);
}


void ArcadeDrive::EnableEncoders(bool invertGains)
{
	// When encoders are enabled, all motors must be inverted from
	// what they normaly would be.
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,  false);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  true);
	// Set max output to be max drive rpm, since the Talons read
	// the encoder speed in rpm.
	m_drive.SetMaxOutput(kMaxDriveRPM);

	// Disable encoders, if already enabled.
	// Not sure this is necessary.
	m_frontLeft.Disable();
	m_backLeft.Disable();
	m_frontRight.Disable();
	m_backRight.Disable();

	// Max voltage should be 12V (Robot has 12V battery).
	m_frontLeft.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_backLeft.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_frontRight.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_backRight.ConfigMaxOutputVoltage(kMaxDriveVoltage);

	// To use the encoders, we need to be in either
	// speed mode or position mode. For driving the
	// robot, speed mode makes more sense.
	m_frontLeft.SetControlMode(CANTalon::kSpeed);
	m_frontLeft.Set(10.0);
	m_backLeft.SetControlMode(CANTalon::kSpeed);
	m_backLeft.Set(10.0);
	m_frontRight.SetControlMode(CANTalon::kSpeed);
	m_frontRight.Set(10.0);
	m_backRight.SetControlMode(CANTalon::kSpeed);
	m_backRight.Set(10.0);

	// Fetch PID gains from the smart dashboard.
	P = SmartDashboard::GetNumber("P", 0);
	I = SmartDashboard::GetNumber("I", 0);
	D = SmartDashboard::GetNumber("D", 0);

	// Set proportional, integral and derivative gains,
	// inverting if appropriate.
	if(invertGains)
	{
		m_frontLeft.SetPID(-P, -I, -D);
		m_backLeft.SetPID(-P, -I, -D);
		m_frontRight.SetPID(-P, -I, -D);
		m_backRight.SetPID(-P, -I, -D);
	}
	else
	{
		m_frontLeft.SetPID(P, I, D);
		m_backLeft.SetPID(P, I, D);
		m_frontRight.SetPID(P, I, D);
		m_backRight.SetPID(P, I, D);
	}

	// We have quadrature encoders
	m_frontLeft.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_backLeft.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_frontRight.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_backRight.SetFeedbackDevice(CANTalon::QuadEncoder);

	// Set encoder pulses per rev
	m_frontLeft.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_backLeft.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_frontRight.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_backRight.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);

	// Enable encoder control with the parameters above.
	m_frontLeft.EnableControl();
	m_backLeft.EnableControl();
	m_frontRight.EnableControl();
	m_backRight.EnableControl();
}

void ArcadeDrive::DisableEncoders()
{
	// Motors have to be inverted for using encoders, so they have
	// to be set back for kPercentVbus mode.
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor,   true);
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,    true);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  false);

	// Output values for kPercentVbus mode are -1..1, so
	// max output should be 1.0
	m_drive.SetMaxOutput(1.0);

	// Change mode to kPercentVbus.
	m_frontLeft.SetControlMode(CANTalon::kPercentVbus);
	m_backLeft.SetControlMode(CANTalon::kPercentVbus);
	m_frontRight.SetControlMode(CANTalon::kPercentVbus);
	m_backRight.SetControlMode(CANTalon::kPercentVbus);

	// Enable the talons
	m_frontLeft.Enable();
	m_backLeft.EnableControl();
	m_frontRight.EnableControl();
	m_backRight.EnableControl();
}


