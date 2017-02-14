#include "SetShooterWheelSpeed.h"

SetShooterWheelSpeed::SetShooterWheelSpeed(float speed) : speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shootersubsystem.get());
}

// Called just before this Command runs the first time
void SetShooterWheelSpeed::Initialize()
{
	CommandBase::shootersubsystem->ShooterWheel(speed);
}

// Called repeatedly when this Command is scheduled to run
void SetShooterWheelSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetShooterWheelSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetShooterWheelSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShooterWheelSpeed::Interrupted()
{

}
