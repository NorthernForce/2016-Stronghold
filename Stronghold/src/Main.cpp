#include "Main.h"
#include "Commands/AutonomousDrive.hpp"


Main::Main() : lw(0), autocmd(), m_chooser()
{
	m_chooser = new SendableChooser();
}

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

GyroSensor& Main::getGyroSensor()
{
	return getRobot().m_gyro;
}

Flashlight& Main::getFlashlight()
{
	return getRobot().m_flashlight;
}

void Main::RobotInit()
{
	m_oi.init();
	m_drive.init();
	m_intake.init();
	m_shooter.init();
	m_gyro.init();
	m_flashlight.init();

	m_chooser->AddDefault("Low Bar Start", new Auto());
	m_chooser->AddObject("Drive Straight", new StraightAuto());
	//m_chooser->AddObject("Spy start, new Auto3());
	SmartDashboard::PutData("Autonomous modes", m_chooser);
	lw = LiveWindow::GetInstance();

	CameraServer::GetInstance()->SetQuality(50);
	CameraServer::GetInstance()->StartAutomaticCapture();
}

void Main::AutonomousInit()
{
	autocmd = (Command *) m_chooser->GetSelected();
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
	double speed = getShooter().GetCurrent();
	SmartDashboard::PutNumber("Current", speed);
	double opticalOne = getOpticalSensors().GetSensorFront();
	double opticalTwo = getOpticalSensors().GetSensorBack();
	SmartDashboard::PutNumber("OpticalFront", opticalOne);
	SmartDashboard::PutNumber("OpticalBack", opticalTwo);

	getGyroSensor().GetGyro();

	m_drive.PutEncoderValues();

	//double intakeNumber = getIntake().GetPosition();

	//SmartDashboard::PutNumber("Intake Encoder", intakeNumber);
}

void Main::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Main);

