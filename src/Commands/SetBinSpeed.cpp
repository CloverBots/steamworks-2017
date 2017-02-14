#include "SetBinSpeed.h"

SetBinSpeed::SetBinSpeed(float speed) : speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SetBinSpeed::Initialize()
{
	CommandBase::shootersubsystem->BinSpeed(speed);
}

// Called repeatedly when this Command is scheduled to run
void SetBinSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetBinSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetBinSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetBinSpeed::Interrupted()
{

}
