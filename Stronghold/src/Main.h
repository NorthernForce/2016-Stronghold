#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/ArcadeDrive.h"

class Main : public IterativeRobot
{
	public:
		Main();
		virtual ~Main();

		static Main& 				getRobot();
		static OI& 					getOI();
		static ArcadeDrive&			getDrive();


	private:
		LiveWindow 		   *lw;
	//	Command*           autocmd;
		OI				   m_oi;
		ArcadeDrive		   m_drive;

		virtual void RobotInit();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();
};

