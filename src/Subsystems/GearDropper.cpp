#include "GearDropper.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/OperateGearFromInput.h"
#include "../FuncCommand.h"

GearDropper::GearDropper() : Subsystem("GearDropper"), m_open(false)
{
	pTalon = new Talon(RobotMap::GEAR_TALON);
	//pSpike = new Relay(RobotMap::GEAR_SPIKE);
	pOpenLimSwitch = new DigitalInput(RobotMap::GEAR_OPEN_SWITCH);
	pClosedLimSwitch = new DigitalInput(RobotMap::GEAR_CLOSED_SWITCH);
}

void GearDropper::InitDefaultCommand()
{
	//SetDefaultCommand(new FuncCommand(std::bind(&GearDropper::PrintSwitchStatus, this), { this }));
}

void GearDropper::SetDoorDirection(Relay::Value direction)
{
	switch (direction)
	{
	case Relay::Value::kForward:
		pTalon->Set(-m_speed);
		break;
	case Relay::Value::kReverse:
		pTalon->Set(m_speed);
		break;
	default:
		pTalon->Set(0.0f);
		break;
	}
	//pSpike->Set(direction);
}

bool GearDropper::IsOpenTriggered()
{
	return !pOpenLimSwitch->Get();
}

bool GearDropper::IsClosedTriggered()
{
	return !pClosedLimSwitch->Get();
}

void GearDropper::PrintSwitchStatus()
{
	std::cout << "Open: " << GearDropper::IsOpenTriggered() << std::endl << "Closed: " << GearDropper::IsClosedTriggered() << std::endl;
}

void GearDropper::SetOpen(bool open)
{
	m_open = open;
}

bool GearDropper::IsOpen()
{
	return m_open;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
