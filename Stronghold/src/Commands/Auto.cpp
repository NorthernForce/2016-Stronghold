#include "Auto.h"
#include "Main.h"
#include "AutonomousDrive.hpp"
#include "ShootBall.hpp"
#include "SetShooterMode.hpp"



Auto::Auto()
{
	AddParallel(new SetShooterMode<ShooterOn>());
	AddSequential(new AutonomousDrive<DriveStraight>(5, 0.8, 4100, 0)); //third arg was 4700
	AddSequential(new AutonomousDrive<DriveTurn>(2, 0.8, 0, 33.5));
	AddSequential(new AutonomousDrive<DriveStraight>(3, 0.8, 600, 0));
	AddSequential(new ShootBall());
}



/*
 * Low bar start: go under, turn, shoot
 * Middle start: drive forward, turn, go under low bar, turn, shoot
 * Spy start: position, shoot
 */

//
