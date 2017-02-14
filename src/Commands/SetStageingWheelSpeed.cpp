#include "SetStageingWheelSpeed.h"

SetStageingWheelSpeed::SetStageingWheelSpeed(float speed) : speed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shootersubsystem.get());
}

// Called just before this Command runs the first time
void SetStageingWheelSpeed::Initialize()
{
	CommandBase::shootersubsystem->StageingWheel(speed);
}

// Called repeatedly when this Command is scheduled to run
void SetStageingWheelSpeed::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetStageingWheelSpeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetStageingWheelSpeed::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetStageingWheelSpeed::Interrupted()
{

}
