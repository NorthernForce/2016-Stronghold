#pragma once

#include "WPILib.h"
#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/ArcadeDrive.h"
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Commands/Auto.h"

class Main : public IterativeRobot
{
	public:
		Main();
		virtual ~Main();

		static Main& 				getRobot();
		static OI& 					getOI();
		static ArcadeDrive&			getDrive();
		static Intake&				getIntake();
		static Shooter&				getShooter();


	private:
		LiveWindow 		   *lw;
		Command*           autocmd;
		OI				   m_oi;
		ArcadeDrive		   m_drive;
		Intake			   m_intake;
		Shooter			   m_shooter;

		virtual void RobotInit();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();
};

