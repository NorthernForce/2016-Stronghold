#include "OpticalSensors.h"


OpticalSensors::OpticalSensors() :
	SubsystemWithCommand<void>("Optical Sensors"),
	m_opticalFront(9),
	m_opticalBack(8)
{}

float OpticalSensors::GetSensorFront()
{
	return m_opticalFront.Get();
}

float OpticalSensors::GetSensorBack()
{
	return m_opticalBack.Get();
}
