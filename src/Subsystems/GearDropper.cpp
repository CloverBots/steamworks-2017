#include "GearDropper.h"
#include "../RobotMap.h"
#include "../CommandBase.h"

GearDropper::GearDropper() : Subsystem("GearDropper")
{
	pSpike = new Relay(RobotMap::GEAR_SPIKE);
	pOpenLimSwitch = new DigitalInput(RobotMap::GEAR_OPEN_SWITCH);
	pClosedLimSwitch = new DigitalInput(RobotMap::GEAR_CLOSED_SWITCH);
}

void GearDropper::InitDefaultCommand()
{
}

Relay* GearDropper::GetSpike()
{
	return pSpike;
}

bool GearDropper::IsOpenTriggered()
{
	return pOpenLimSwitch->Get();
}

bool GearDropper::IsClosedTriggered()
{
	return pClosedLimSwitch->Get();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
