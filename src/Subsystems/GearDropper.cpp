#include "GearDropper.h"
#include "../RobotMap.h"
#include "../CommandBase.h"

GearDropper::GearDropper() : Subsystem("GearDropper") {

}

void GearDropper::InitDefaultCommand()
{

}

void GearDropper::DropGear()
{
	CommandBase::oi->GetJoystick()->GetRawButton(6);
}

void GearDropper::CloseDoor()
{
	CommandBase::oi->GetJoystick()->GetRawButton(5);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
