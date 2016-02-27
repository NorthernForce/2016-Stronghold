#pragma once

/**
 * The RobotMap is a mapping from the ports for sensors and actuators
 * to variable names. This provides flexibility with changing wiring, makes checking
 * the wiring easier, and significantly reduces the number of magic numbers
 * floating around.
 */


enum XBoxJoystickButtonPort
{
	// Apparently, the buttons are one-based after all...

	kXBoxButtonA = 1,
	kXBoxButtonB = 2,
	kXBoxButtonX = 3,
	kXBoxButtonY = 4,
	kXBoxButtonLeft = 5,
	kXBoxButtonRight = 6,
	kXBoxButtonBack = 7,
	kXBoxButtonStart = 8,
	kXBoxButtonLeftJoystick = 9,
	kXBoxButtonRightJoystick = 10,
};



enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 1,
 	kAttackJoystickButton2 = 2,
 	kAttackJoystickButton3 = 3,
 	kAttackJoystickButton4 = 4,
 	kAttackJoystickButton5 = 5,
 	kAttackJoystickButton6 = 6,
 	kAttackJoystickButton7 = 7,
 	kAttackJoystickButton8 = 8,
 	kAttackJoystickButton9 = 9,
 	kAttackJoystickButton10 = 10,
 	kAttackJoystickButton11 = 11,
	kAttackJoystickButton12 = 12,
};

enum TalonAdress
{
	kFrontLeftTalon = 3,
	kFrontRightTalon = 4,
	kBackLeftTalon = 1,
	kBackRightTalon = 2,

	kWheelTalon = 8,
	kShooterTalon = 5,
	kAxleTalon = 6,
	kInternalTalon = 7,

};


enum JoystickPort
{
    kDriverStickPort = 0,
    kManipulatorStickPort = 1,
	kXBoxManipulatorPort = 2,
};

struct DefaultPosition
{
	static constexpr float kDegrees = 100.0;
	static constexpr float kValue = kDegrees/360;
};

struct UpPosition
{
	static constexpr float kDegrees = 32.0;
	static constexpr float kValue = kDegrees/360;
};

struct DownPosition
{
	static constexpr float kDegrees = 215.0;
	static constexpr float kValue = kDegrees/360;
};

static const float	kP = 0.2;
static const float	kI = 0;
static const float	kD = 0;

static const int kChannelA = 0; // 6 and 7

static const float kDeadbandLimit = 0.01;
static const float kMaxDriveVoltage = 12.0;
static const float kMaxDriveRPM = 475.0;
static const float kRevsPerFoot = 12.0/(2.0*3.14159*3.0); /* 12in / (1ft * 2.0pi r(in)) */
static const int kEncoderPulsesPerRev = 256;
