#include "GyroSensor.h"


GyroSensor::GyroSensor() :
	SubsystemWithCommand<void>("Gyro Sensor"),
	m_gyro(1) //needs to be checked
{}


float GyroSensor::GetGyroAngle()
{
	return m_gyro.GetAngle();
}

