#include "LiftSubsystem.h"
#include "../RobotMap.h"
#include <WPILib.h>

LiftSubsystem::LiftSubsystem() : Subsystem("LiftSubsystem")
{
	m_pLiftMotor = new Talon(RobotMap::LIFT_TALON);//new Relay(RobotMap::LIFT_SPIKE);
}

void LiftSubsystem::Set(double speed)
{
	m_pLiftMotor->Set(speed);
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

	//m_pLiftMotor->Set(value);
}
