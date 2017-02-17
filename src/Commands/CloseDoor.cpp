#include "CloseDoor.h"

CloseDoor::CloseDoor()
{
	Requires(CommandBase::gearDropper.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void CloseDoor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CloseDoor::Execute()
{
	CommandBase::gearDropper->GetSpike()->Set(Relay::kForward);
}

// Make this return true when this Command no longer needs to run execute()
bool CloseDoor::IsFinished()
{
	return CommandBase::gearDropper->IsClosedTriggered();
}

// Called once after isFinished returns true
void CloseDoor::End()
{
	CommandBase::gearDropper->GetSpike()->Set(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseDoor::Interrupted()
{

}
