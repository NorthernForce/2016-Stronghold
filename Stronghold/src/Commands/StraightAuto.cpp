#include "StraightAuto.h"
#include "Main.h"
#include "AutonomousDrive.hpp"
#include "ShootBall.hpp"
#include "SetShooterMode.hpp"



StraightAuto::StraightAuto()
{
	AddSequential(new AutonomousDrive<DriveStraight>(5, 0.8, 4300, 0)); //third arge was 4700
}



/*
 * Low bar start: go under, turn, shoot
 * Middle start: drive forward, turn, go under low bar, turn, shoot
 * Spy start: position, shoot
 */

//
