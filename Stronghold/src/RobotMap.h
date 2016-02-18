#pragma once

/**
 * The RobotMap is a mapping from the ports for sensors and actuators
 * to variable names. This provides flexibility with changing wiring, makes checking
 * the wiring easier, and significantly reduces the number of magic numbers
 * floating around.
 */


enum XBoxJoystickButtonPort
{
	// New mappings starting in 2015
	kXBoxButtonA = 0,
	kXBoxButtonB = 1,
	kXBoxButtonX = 2,
	kXBoxButtonY = 3,
	kXBoxButtonLeft = 4,
	kXBoxButtonRight = 5,
	kXBoxButtonBack = 6,
	kXBoxButtonStart = 7,
	kXBoxButtonLeftJoystick = 8,
	kXBoxButtonRightJoystick = 9,
};



enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 0,
 	kAttackJoystickButton2 = 1,
 	kAttackJoystickButton3 = 2,
 	kAttackJoystickButton4 = 3,
 	kAttackJoystickButton5 = 4,
 	kAttackJoystickButton6 = 5,
 	kAttackJoystickButton7 = 6,
 	kAttackJoystickButton8 = 7,
 	kAttackJoystickButton9 = 8,
 	kAttackJoystickButton10 = 9,
 	kAttackJoystickButton11 = 10,
	kAttackJoystickButton12 = 11,
};

enum TalonAdress
{
	kFrontLeftTalon = 3, // Needs to be changed/confirmed
	kFrontRightTalon = 4,
	kBackLeftTalon = 1, //swapped 1 and 2
	kBackRightTalon = 2,

	kWheelTalon = 5,
	kAxleTalon = 6,

};


enum JoystickPort
{
    kDriverStickPort = 0,
    kManipulatorStickPort = 1,
	kXBoxManipulatorPort = 2,
};

enum PID
{
	kP = 0,
	kI = 0,
	kD = 0,
};

enum EncoderChannels
{
	kChannelA = 0,
	kChannelB = 1,
};

static const float kDeadbandLimit = 0.01;
static const float kMaxDriveVoltage = 12.0;
static const float kMaxDriveRPM = 475.0;
static const float kRevsPerFoot = 12.0/(2.0*3.14159*3.0); /* 12in / (1ft * 2.0pi r(in)) */
static const int kEncoderPulsesPerRev = 256;
