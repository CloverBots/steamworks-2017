#include "CloseDoor.h"

CloseDoor::CloseDoor()
{
	pSpike = new Relay(0);
	pLimSwitchClosed = new DigitalInput(1);
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
	pSpike->Set(Relay::kForward);
}

// Make this return true when this Command no longer needs to run execute()
bool CloseDoor::IsFinished()
{
	return pLimSwitchClosed->Get();
}

// Called once after isFinished returns true
void CloseDoor::End()
{
	pSpike->Set(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseDoor::Interrupted()
{

}
