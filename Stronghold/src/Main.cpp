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

Intake& Main::getIntake()
{
	return getRobot().m_intake;
}

Shooter& Main::getShooter()
{
	return getRobot().m_shooter;
}

OpticalSensors& Main::getOpticalSensors()
{
	return getRobot().m_optical;
}

void Main::RobotInit()
{
	m_oi.init();
	m_drive.init();
	m_intake.init();
	m_shooter.init();

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
	double voltage = getShooter().GetVoltage();
	SmartDashboard::PutNumber("Voltage", voltage);
	double speed = getShooter().GetSpeed();
	SmartDashboard::PutNumber("Speed", speed);
	double opticalOne = getOpticalSensors().GetSensorFront();
	double opticalTwo = getOpticalSensors().GetSensorBack();
	SmartDashboard::PutNumber("OpticalFront", opticalOne);
	SmartDashboard::PutNumber("OpticalBack", opticalTwo);
}

void Main::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Main);

