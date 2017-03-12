#include "GearDropper.h"
#include "../RobotMap.h"
#include "../CommandBase.h"
#include "../Commands/OperateGearFromInput.h"
#include "../FuncCommand.h"

GearDropper::GearDropper() : Subsystem("GearDropper"), m_open(false)
{
	pSpike = new Relay(RobotMap::GEAR_SPIKE);
	pOpenLimSwitch = new DigitalInput(RobotMap::GEAR_OPEN_SWITCH);
	pClosedLimSwitch = new DigitalInput(RobotMap::GEAR_CLOSED_SWITCH);
}

void GearDropper::InitDefaultCommand()
{
	//SetDefaultCommand(new FuncCommand(std::bind(&GearDropper::PrintSwitchStatus, this), { this }));
}

void GearDropper::SetDoorDirection(Relay::Value direction)
{
	pSpike->Set(direction);
}

Relay* GearDropper::GetSpike()
{
	return pSpike;
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
