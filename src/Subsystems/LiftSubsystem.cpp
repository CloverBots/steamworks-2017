#include "LiftSubsystem.h"
#include "../RobotMap.h"

LiftSubsystem::LiftSubsystem() : Subsystem("LiftSubsystem")
{
	m_pLiftMotor = new DigitalOutput(RobotMap::LIFT_SPIKE);
}

void LiftSubsystem::setMotor(bool b)
{
	m_pLiftMotor->Set(b);
}
