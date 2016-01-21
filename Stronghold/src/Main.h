#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "OI.h"

class Main : public IterativeRobot
{
	public:
		Main();
		virtual ~Main();

		static Main& 				getRobot();
		static OI& 					getOI();


	private:
		LiveWindow 		   *lw;
	//	Command*           autocmd;
		OI				   m_oi;

		virtual void RobotInit();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();
};

