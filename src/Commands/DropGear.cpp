#include "DropGear.h"

DropGear::DropGear()
{
	pSpike = new Relay(0);
	pLimSwitchOpen = new DigitalInput(0);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void DropGear::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DropGear::Execute()
{
	pSpike->Set(Relay::kReverse);
}

// Make this return true when this Command no longer needs to run execute()
bool DropGear::IsFinished()
{
	return pLimSwitchOpen->Get();
}

// Called once after isFinished returns true
void DropGear::End()
{
	pSpike->Set(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DropGear::Interrupted()
{

}
