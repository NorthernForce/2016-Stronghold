#include "Main.h"

Main::Main() : lw(0), autocmd()
{}

Main::~Main()
{
	delete autocmd;
}

Main& Main::getRobot()
{
	return static_cast<Main&>(RobotBase::getInstance());
}

OI& Main::getOI()
{
	return getRobot().m_oi;
}

ArcadeDrive& Main::getDrive()
{
	return getRobot().m_drive;
}

void Main::RobotInit()
{
	m_oi.init();
	m_drive.init();

	autocmd = new Auto();
	lw = LiveWindow::GetInstance();
}

void Main::AutonomousInit()
{
	autocmd->Start();
}

void Main::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TeleopInit()
{
}

void Main::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Main);

