#include "LiftSubsystem.h"
#include "../RobotMap.h"

LiftSubsystem::LiftSubsystem() : Subsystem("LiftSubsystem")
{
	m_pLiftMotor = new Relay(RobotMap::LIFT_SPIKE);
}

void LiftSubsystem::setMotor(bool b)
{
	m_pLiftMotor->Set(b ? Relay::kForward : Relay::kOff);
}
