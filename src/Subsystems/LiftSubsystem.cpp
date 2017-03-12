#include "LiftSubsystem.h"
#include "../RobotMap.h"
#include <WPILib.h>

LiftSubsystem::LiftSubsystem() : Subsystem("LiftSubsystem")
{
	m_pLiftMotor = new Relay(RobotMap::LIFT_SPIKE);
}

void LiftSubsystem::Set(Relay::Value value)
{
//	switch (value)
//	{
//	case Relay::kForward:
//		std::cout << "Forward\n";
//		break;
//	case Relay::kReverse:
//		std::cout << "Reverse\n";
//		break;
//	case Relay::kOff:
//		std::cout << "Off\n";
//		break;
//	default:
//		std::cout << "Something else\n";
//		break;
//	}

	m_pLiftMotor->Set(value);
}
