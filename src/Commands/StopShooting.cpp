#include "StopShooting.h"

StopShooting::StopShooting()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StopShooting::Initialize()
{
	CommandBase::shooterSubsystem->ShooterWheel(0.0f);
	CommandBase::shooterSubsystem->StagingWheel(0.0f);
	CommandBase::shooterSubsystem->BinSpeed(0.0f);
}

// Called repeatedly when this Command is scheduled to run
void StopShooting::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopShooting::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StopShooting::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopShooting::Interrupted()
{

}
